// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

void MineGenesis(CBlock genesis){
    // This will figure out a valid hash and Nonce if you're creating a different genesis block:
    uint256 hashTarget = CBigNum().SetCompact(Params().ProofOfWorkLimit().GetCompact()).getuint256();
    printf("Target: %s\n", hashTarget.GetHex().c_str());
    uint256 newhash = genesis.GetHash();
    uint256 besthash;
    memset(&besthash,0xFF,32);
    while (newhash > hashTarget) {
        ++genesis.nNonce;
        if (genesis.nNonce == 0){
            printf("NONCE WRAPPED, incrementing time");
            ++genesis.nTime;
        }
    newhash = genesis.GetHash();
    if(newhash < besthash){
        besthash=newhash;
        printf("New best: %s\n", newhash.GetHex().c_str());
    }
    }
    printf("Found Genesis, Nonce: %ld, Hash: %s\n", genesis.nNonce, genesis.GetHash().GetHex().c_str());
    printf("Gensis Hash Merkle: %s\n", genesis.hashMerkleRoot.ToString().c_str());
}

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7*24*60*60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//
// OVOCoin Main
//

class COVOCoinMainParams : public CChainParams {
public:
    COVOCoinMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x4c;
        pchMessageStart[1] = 0x65;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0x74;
        //vAlertPubKey = ParseHex("044e0d4bc823e20e14d66396a64960c993585400c53f1e6decb273f249bfeba0e71f140ffa7316f2cdaaae574e7d72620538c3e7791ae9861dfe84dd2955fc85e8");
        nDefaultPort = 11337;
        nRPCPort = 11336;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 20);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.
        //
        //CBlock(hash=000001faef25dec4fbcf906e6242621df2c183bf232f263d0ba5b101911e4563, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=12630d16a97f24b287c8c2594dda5fb98c9e6c70fc61d44191931ea2aa08dc90, nTime=1393221600, nBits=1e0fffff, nNonce=164482, vtx=1, vchBlockSig=)
        //  Coinbase(hash=12630d16a9, nTime=1393221600, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //    CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a24323020466562203230313420426974636f696e2041544d7320636f6d6520746f20555341)
        //    CTxOut(empty)
        //  vMerkleTree: 12630d16a9
        const char* pszTimestamp = "National Post: Recreational marijuana becomes legal in Canada on October 16, 2018";
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 0 << CBigNum(63) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1546050408, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1546050408;
        genesis.nBits    = 0x1e0fffff;
        genesis.nNonce   = 1343757;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0fd3ac74da745c12998bdb5885d237001a8392103fe9f70408f4c66e164964ed"));
        assert(genesis.hashMerkleRoot == uint256("5b332f35ed4b00a95f59bdbfe224dc315e5941f7b08b912c89ffe4a88349af36"));

        vSeeds.push_back(CDNSSeedData("Seednode1", "ovocoin.com"));
        vSeeds.push_back(CDNSSeedData("Seednode2", "masterpool.pw"));
        vSeeds.push_back(CDNSSeedData("Seednode3", "109.108.77.134"));
        vSeeds.push_back(CDNSSeedData("Seednode4", "62.80.181.141"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 13);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 125);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1, (63+128));
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xC2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0xDD).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nLastPOWBlock = 100000;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::IMPLEUMMAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static COVOCoinMainParams ovocoinMainParams;

//
// OVOCoin Testnet
//

class COVOCoinTestNetParams : public COVOCoinMainParams {
public:
    COVOCoinTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0x03;
        pchMessageStart[1] = 0x04;
        pchMessageStart[2] = 0x05;
        pchMessageStart[3] = 0x06;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);
        vAlertPubKey = ParseHex("044e0d4bc823e20e14d66396a64960c993585400c53f1e6decb273f249bfeba0e71f140ffa7316f2cdaaae574e7d72620538c3e7791ae9861dfe84dd2955fc85e8");
        nDefaultPort = 11336;
        nRPCPort = 11338;

        strDataDir = "ovocointestnet";
        // Modify the testnet genesis block so the timestamp is valid for a later start.
        unsigned int tempComp = bnProofOfWorkLimit.GetCompact();
        genesis.nBits  = tempComp;//520159231;
        genesis.nNonce = 469274;
        genesis.nTime    = 1486949366;
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("bde3c0e4d5e60b6257175bbc2df103277b768e9a788b1e2e81eafef85f34e957"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("62.80.181.141", "62.80.181.141"));
        vSeeds.push_back(CDNSSeedData("109.108.77.134", "109.108.77.134"));
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 102); // stratis test net start with T
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1, 65 + 128);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nLastPOWBlock = 100000;
    }
    virtual Network NetworkID() const { return CChainParams::IMPLEUMTEST; }
};
static COVOCoinTestNetParams ovocoinTestParams;

//
// OVOCoin Regression test
//
class COVOCoinRegTestParams : public COVOCoinTestNetParams {
public:
    COVOCoinRegTestParams() {
        pchMessageStart[0] = 0x03;
        pchMessageStart[1] = 0x04;
        pchMessageStart[2] = 0x05;
        pchMessageStart[3] = 0x06;
        bnProofOfWorkLimit = CBigNum(~uint256("7fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"));
        genesis.nTime = 1520158227;
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 1503601;
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 16371;
        nRPCPort = 16372;
        strDataDir = "regtest";
//        MineGenesis(genesis);
        assert(hashGenesisBlock == uint256("5662e51a2b81d176a4e02f1f8f0e50c3ebd31e4bad2a5a95abe97fb2e85930b1"));

        vSeeds.clear();  // Regtest mode doesn't have any DNS seeds.
    }

    virtual bool RequireRPCPassword() const { return false; }
    virtual Network NetworkID() const { return CChainParams::IMPLEUMREGTEST; }
};
static COVOCoinRegTestParams ovocoinRegTestParams;

static CChainParams *pCurrentParams = &ovocoinMainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::IMPLEUMMAIN:
            pCurrentParams = &ovocoinMainParams;
            break;
        case CChainParams::IMPLEUMTEST:
            pCurrentParams = &ovocoinTestParams;
            break;
        case CChainParams::IMPLEUMREGTEST:
            pCurrentParams = &ovocoinRegTestParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    bool fRegTest = GetBoolArg("-regtest", false);
    bool fTestNet = GetBoolArg("-testnet", false);

    if (fTestNet && fRegTest) {
        return false;
    }

    if (fRegTest) {
        SelectParams(CChainParams::IMPLEUMREGTEST);
    } else if (fTestNet) {
        SelectParams(CChainParams::IMPLEUMTEST);
    } else
        SelectParams(CChainParams::IMPLEUMMAIN);

    return true;
}
