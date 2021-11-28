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
    ~MDNS();

    static void addService(Protocol protocol, std::string serviceType, const std::string serviceName, uint16_t port,
                           std::vector<std::string>&& txtEntries,
                           std::vector<std::string>&& subServices);

    static bool begin();
    static void announce();
    static void process();
    static bool processQueries();
    static void stop();

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

    static UDP* udp;

    // static meta records to re-use labels
    static MetaRecord metaLOCAL;
    static MetaRecord metaUDP;
    static MetaRecord metaTCP;
    static MetaRecord metaDNSSD;
    static MetaRecord metaSERVICES;

    // actual records that are checked
    static ARecord hostRecord;
    static HostNSECRecord hostNSECRecord;

    // vectors of extra records to iterate over them
    static std::vector<std::unique_ptr<Record>> records;
    static std::vector<std::unique_ptr<MetaRecord>> subMetaRecords;

    static const IPAddress ip;
    static const auto port = uint16_t{5353};

    static Query getQuery();

    static void processQuery(const Query& q);
    static void processQuestion(const Query::Question& question);
    static void writeResponses();

    static void udpGet(uint8_t& v)
    {
        if (udp->available() >= 1) {
            v = udp->read();
        }
    }

    static void udpGet(uint16_t& v)
    {
        if (udp->available() >= 2) {
            v = (uint16_t(udp->read()) << 8) + uint16_t(udp->read());
        }
    }

    static void udpGet(uint32_t& v)
    {
        if (udp->available() >= 4) {
            v = (uint32_t(udp->read()) << 24) + (uint32_t(udp->read()) << 16) + (uint32_t(udp->read()) << 8) + uint32_t(udp->read());
        }
    }
};
