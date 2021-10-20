#pragma once
// #include "Buffer.h"
// #include "Label.h"
#include "Record.h"
#include "UDPMessage.h"
#include <map>
#include <memory>
#include <string>
#include <vector>

class MDNS {
public:
    enum class Protocol {
        UDP,
        TCP,
    };

    MDNS(const std::string& hostname);
    ~MDNS() = default;

    void addService(Protocol protocol, std::string serviceType, const std::string serviceName, uint16_t port,
                    std::vector<std::string>&& txtEntries,
                    std::vector<std::string>&& subServices);

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

    static UDP udp;

    // static meta records to re-use labels
    static std::shared_ptr<MetaRecord> metaLOCAL()
    {
        static auto record = std::make_shared<MetaRecord>(Label("local", {}));
        return record;
    }
    static std::shared_ptr<MetaRecord> metaUDP()
    {
        static auto record = std::make_shared<MetaRecord>(Label("_udp", metaLOCAL()));
        return record;
    }
    static std::shared_ptr<MetaRecord> metaTCP()
    {
        static auto record = std::make_shared<MetaRecord>(Label("_tcp", metaLOCAL()));
        return record;
    }
    static std::shared_ptr<MetaRecord> metaDNSSD()
    {
        static auto record = std::make_shared<MetaRecord>(Label("_dns-sd", metaUDP()));
        return record;
    }
    static std::shared_ptr<MetaRecord> metaSERVICES()
    {
        static auto record = std::make_shared<MetaRecord>(Label("_services", metaDNSSD()));
        return record;
    }

    // actual records that are checked
    static std::shared_ptr<ARecord> hostRecord;

    // vectors of records to iterate over them
    static std::vector<std::shared_ptr<Record>> records;
    static std::vector<std::shared_ptr<MetaRecord>> metaRecords;

    static const IPAddress ip;
    static const auto port = uint16_t{5353};

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
