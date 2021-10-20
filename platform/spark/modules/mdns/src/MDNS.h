#pragma once
// #include "Buffer.h"
// #include "Label.h"
#include "Record.h"
#include "UDPMessage.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

#define MDNS_ADDRESS IPAddress(224, 0, 0, 251)
#define MDNS_PORT 5353

#define BUFFER_SIZE 512

class MDNS {
public:
    enum class Protocol {
        UDP,
        TCP,
    };

    MDNS(const std::string& hostname);
    ~MDNS()
    {
    }

    void addService(Protocol protocol, std::string serviceType, const std::string serviceName, uint16_t port,
                    std::vector<std::string>&& txtEntries = std::vector<std::string>(),
                    std::vector<std::string>&& subServices = std::vector<std::string>());

    bool begin(bool announce = false);

    bool processQueries();

private:
    struct QueryHeader {
        uint16_t id;
        uint16_t flags;
        uint16_t qdcount;
        uint16_t ancount;
        uint16_t nscount;
        uint16_t arcount;
    };

    struct Query {
        Query()
            : header{0}
        {
        }
        ~Query() = default;

        struct Question {
            std::vector<std::string> qname;
            std::vector<uint16_t> qnameOffset;
            uint16_t qtype = 0;
            uint16_t qclass = 0;
        };

        QueryHeader header;
        std::vector<Question> questions;
    };

    UDP udp;

    // meta records for re-using labels
    std::shared_ptr<MetaRecord> metaLOCAL;
    std::shared_ptr<MetaRecord> metaUDP;
    std::shared_ptr<MetaRecord> metaTCP;
    std::shared_ptr<MetaRecord> metaDNSSD;
    std::shared_ptr<MetaRecord> metaSERVICES;

    // actual records that are checked
    std::shared_ptr<ARecord> hostRecord;

    // vectors of records to iterate over them
    std::vector<std::shared_ptr<Record>> records;
    std::vector<std::shared_ptr<MetaRecord>> metaRecords;

    Query getQuery();

    void processQuery(const Query& q);
    void processQuestion(const Query::Question& question);
    void writeResponses();

    void udpGet(uint8_t& v)
    {
        if (udp.available() >= 1) {
            v = udp.read();
        }
    }

    void udpGet(char& v)
    {
        auto cptr = reinterpret_cast<uint8_t*>(&v);
        udpGet(*cptr);
    }

    void udpGet(uint16_t& v)
    {
        if (udp.available() >= 2) {
            v = (uint16_t(udp.read()) << 8) + uint16_t(udp.read());
        }
    }

    void udpGet(uint32_t& v)
    {
        if (udp.available() >= 4) {
            v = (uint32_t(udp.read()) << 24) + (uint32_t(udp.read()) << 16) + (uint32_t(udp.read()) << 8) + uint32_t(udp.read());
        }
    }
};
