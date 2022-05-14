// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "txdb.h"
#include "main.h"
#include "uint256.h"


static const int nCheckpointSpan = 500;

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    // 
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        ( 0,   uint256("0x00000da9f638b705f00f8f6fc533aeed36e656996bf31ffc52d56dfdd6b25b5c") ) 
        ( 100,   uint256("0xa8bf6b2ef5e0d56f991681ad3af689ca230243e20ad3200011c23b498082d2df") ) 
        ( 510,   uint256("0xce18f2c1153e2c030618a05a1bee8e7dcead88f8b54b20521f69ddcdaed356d2") ) 
        ( 1010,   uint256("0x2f84b7589d9eb1eb0b167e57235f828b89a21186e8b6e110c17982bb993df5b3") ) 
        ( 5050,   uint256("0x72ea7a1164cefcf41c10bdb70323ba051e67b33de8be536879930e346bbc18bf") ) 
        ( 10010,   uint256("0xe3d5cb1ec5b3642e1484deca9719773b5474ad2503533bb4da5adbe461eb8aa0") ) 
        ( 51000,   uint256("0x5d4e4673ae13e9e0d333a00640d6962fc35a8fb56f166230aa01c1315da67955") ) 
        ( 81000,   uint256("0xac0d92378b7ac09e1814a016a9d1f64a846fd6b4c7fb9f158b00c32b950537f5") ) 
        ( 91000,   uint256("0x5beef44f6f5d0de6e9f5fda718c59b166c628ba16663ff5ed8cb34398a86119d") ) 
        ( 101000,   uint256("0xd7d4aa70b5144e133b0257660515a859e48e557306b3aa30465809ed5cc2e755") ) 
        ( 120001,   uint256("0xc926251e245663560fa8635f8d72ff17447035ccfb5eccd785544f6ef4862fe0") ) 
        ( 130003,   uint256("0x28cd692e1440204f73bbecb420281964851c084c6528f5501a88effac8043563") ) 
        ( 150003,   uint256("0x15005559eebf68a2da451734dda83329df6b2ee63c8b706a6f32516f1544f087") ) 
        ( 170003,   uint256("0x3df6434a6a99470e5567f95fce8ce7efe763a515ce06dc8c3fba9a23f32c9b4b") ) 
        ( 180008,   uint256("0x0847a784f81a2c351a9fdb100c48a5917b425eaf9fbeb116b95a17db9aa4bd13") ) 
        ( 190009,   uint256("0xbfd876d81f6d9dc1db9c5e5531e402362eae8923a4f6fa7aa213d31e0e5a15d6") ) 
        ( 199909,   uint256("0x740e26d507678dc6ed330a32c06b2bcde04b4ba0fadb7afcf3902562069ef54b") ) 
        ( 200009,   uint256("0x434126756e0d2c1725b1e28dc79ba0045e287abfbc36f5bb90228cc19e78171b") ) 
        ( 200909,   uint256("0x58104c2c111496807cb251b88a171feec37c150fc885f50778e06b1a847dd903") ) 
        ( 201009,   uint256("0x8d4bf9be4b40bca5eb939af3f6de3ab73989fa8bcc6eb738ff64874f7e9b4a4b") ) 
        ( 209009,   uint256("0xf509518051882886184c5294151506a370e1072cd21b8d5c7332ab4bd70cf5c8") ) 
        ( 220009,   uint256("0x74b9cd557fef4484b7d9dbb4afd6b3032676df91807b9e9d957ab319ec097523") ) 
        ( 236011,   uint256("0xf5de325d3daa42d6e238e36fe1dc694b0ef3e34b57ef31f2e9b282fba14649d9") ) 
        ( 250011,   uint256("0x0135bb56254f6391b19bf3f00b8550a26adb835037c6af158a4b080949afa596") ) 
        ( 260011,   uint256("0x454fe457551e40f73a4942293323504808dc5b30835ce218df00f59023b47878") ) 
        ( 270007,   uint256("0xf1eece6004c6be3c077cd9745ff3e464ea928fc9b70d7b6246550226bd9028b5") ) 
        ( 280009,   uint256("0x93a0417180cd3340214710764cb2d5fca0a2ddf706332ee5cd6a94e063ae5b58") ) 
        ( 290011,   uint256("0x4f9e294fdbd3953f360ffb913016f228523806b8b70f9d2c43a6308401858126") ) 
        ( 300000,   uint256("0xcb717d710334fa7487fe9ea5d4c84331fe3c112f785ed063f9de1c100d69393f") ) 
        ( 300101,   uint256("0xc5c17b0e59d8390eaaeecca8d6942e0441848fd4343783a1c4936ba321620579") ) 
        ( 301011,   uint256("0x32f751b86514477d02a3d4edcc28822ef7f397dcb20e8d54ab878799d5c4d137") ) 
        ( 309011,   uint256("0x141e1f80c1e3a2fcc8f73e561560ebe71b18a8eaf66a0d24edab397be9c78e33") ) 
        ( 310000,   uint256("0xac487692c1f2547643309b7ac195f2af126642fde3b78226d82a45f283d0ac65") ) 
        ( 310511,   uint256("0x5c553b70753586a4665be84dc04b925b8622e9f9620f4da896ccb311806962a8") ) 
        ( 311111,   uint256("0x418c14e4b57707d72b06e78d8476f4758305abf863673fa8e89faf25d6335923") ) 
        ( 326511,   uint256("0xb8f27e137dcda4bb4755d77cbaf63431b9281fcf80d661b0873953740bb74d48") ) 
        ( 338533,   uint256("0x5c478b2ed4e185f8dde07e056fd8d92982c503c8c2344a1cf1e6b3c6d6ed8afd") ) 
        ( 341544,   uint256("0xf13a59423545407acb671cd8c10f9e6d7e472fb35df54fb2447ef5aff9f969a0") ) 
        ( 359577,   uint256("0x3088af868891661bc574486e8993f903217e72b3ad9c0029c4c6ee4a5222d016") ) 
        ( 364599,   uint256("0xa3ccc9b521206e80a2b128bebc41e476f45718128f2fba398260a6fd3bb8e9ca") ) 
        ( 378522,   uint256("0x9a61e3a12c4d012114522ee43d1ad8245755870979a1c1e06a3ee9d9f4807c96") ) 
        ( 390522,   uint256("0xd8e75fe6fdc69745ec5fc202c121997a64f100b818976e978a556f3b00596421") ) 
        ( 405000,   uint256("0x8b7f49ecf9fbb409299bc960ce1a413ad8889b5ebd3f53f303f7e21eed7113b9") ) 
        ( 410100,   uint256("0x35a526d78d4251f7bfa9992bb568336dbbc5eefff680316883494046deaa5dcc") ) 
        ( 415100,   uint256("0xcb6944202bbe6ce9504c0403f97f727f73a391f3acbdccf626af6e52e55ec61b") ) 
        ( 422100,   uint256("0xf81ab09845bc4deb167d4e147f41c3a82bd9c7df7f93dbc8bf606908df18100a") ) 
        ( 430466,   uint256("0x421b268ac3c668578cc40ff0f1989448b5fff8d8b012b9818814cb4dd831678a") ) 
        ( 438465,   uint256("0x56d9e63340de9671650aae545bab353bdcee0f1931c87f05402b984cbc75c7a5") ) 
        ( 444429,   uint256("0xaba34ec91fbb2a441693e88b11eab16502e2cb847821a1a8bdbf02a4b99172f3") ) 
        ( 450413,   uint256("0x6da428f2d906c6a3686ea58fe2e2eab417d1927bad697968bbf77537f173618b") ) 
        ( 456913,   uint256("0x61bf92c7af30c2a9b666151d8ccf33d03eb5a2be51afe9552c6ef1a7a648474c") ) 
        ( 460447,   uint256("0x280a20409ce3dad6adfdb88e123872180fe363316ebd804f860717e4a31e6972") ) 
        ( 475321,   uint256("0x9f60caec7e89ba2c3778dfe25156905322cd67938659385e0fd31b7235a0d95a") ) 
        ( 488987,   uint256("0x51eea478eb629ecb93af620d89a16bf1f6886e3b76d214998d556e545409c276") ) 
        ( 489000,   uint256("0x9606112c7799b5ed96160e9f66195c6a0a5da5df10f48d4d9e9677684c8e9f5a") ) 
        ( 490140,   uint256("0x4ce33891166e49b554f9c1dd3ecf8c8b6d2efce70d9d5ae0e30e6b929c2ed3f8") ) 
        ( 494247,   uint256("0xe8014b2bbe56894f577c1f996de220ff8ded8daadfd8717092eb91ae0a65bf38") ) 
        ( 499987,   uint256("0xb7d9c31830dffd29dc4aa5741a7f6276587822203763603cad361b90f27bc42c") ) 
        ( 500000,   uint256("0x44ee1dcaeb5d88fb1ece79d25804c811c15967221a8832d97972fe92341ab061") ) 
        ( 505000,   uint256("0xb53474bd55524d1fff78055c86765f1f2b54ff0842ab9c2f888539c894144ff3") ) 
        ( 510000,   uint256("0x71c863a217049b2f2374b516121d0b258fee93ecae95c7e4058f2e471c24bb52") ) 
        ( 515000,   uint256("0xdd26ef283b9d4c5035258d8036dfa51f203c8434a7d39e931a5375e0f3d6016f") ) 
        ( 520101,   uint256("0x6acf8a15701254fa72aa45321d49585c5262e92d0e95ce13463660a429001adf") ) 
        ( 530205,   uint256("0x716374084abc4021280da9655629c2aad9dcdf8bc354452ec7f07fa38e0dac6a") ) 
        ( 535101,   uint256("0xb3c4f257c7ea4e018d2dd783f2da744b8ca479045ac58831904fa948583d37d1") ) 
        ( 550505,   uint256("0x05c9a311fded0ac57698183bcab2dc20c5f6b14282556bfb7e5e1193ef6e04f9") ) 
        ( 565209,   uint256("0x77e68ccf48157d95d95482ce68d2fa4845df9d1e519e0d32bd2209ff51938f4d") ) 
        ( 580501,   uint256("0x9a8f0cfe29de0cc65c3fba0eb85d104848ada89f3133d90cc77ee7130f33e976") )
        ( 595209,   uint256("0x2cb4b635fceb8608e68380f5d2bf23037cee6c4d5910eeed68ea41c4869f6c09") )
        ( 600200,   uint256("0x194897bbe35695458a68d6a93eaa847cd5815fb54ec7e63d507025fa4bdebd64") )
        ( 610468,   uint256("0x5b478e671e19456187feba26eb8c473d94ecf1c566f64e571d1fa16fbba6d6fd") )
        ( 630746,   uint256("0xad3f1743428e53eacdf141aebee71d1a7313ef9dcf0aa0897a4ec6954f6aa8bb") )
        ( 650123,   uint256("0x70b73d87ff044e5e3208490821b6066ccaa83362cfcfa350b759c625dee22d39") )
        ( 665432,   uint256("0xe979f8a1201f0f729a0874b24f4a4ed72cfc4f7f0fc6b3de5ef4f690aad63209") )
        ( 687987,   uint256("0x46d8e83781e1cab51a6ccaf1444e3076de340ca081204c89e12b73d7de557e71") )
        ( 692456,   uint256("0x0983d75acf2b1e9e83831136480555d9de2e286cd6a451667c121fc4b799b55b") )
        ( 711982,   uint256("0x84cb748ae424df9291dfffcae72c9c9669d2308e6121d54b8317a5e9045d495b") )
        ( 722852,   uint256("0xfa503c34362eabe4cdcb93187eb951e3c918e4377acbd3e4e6ce355d60678ca3") )
        ( 733028,   uint256("0xaf9bcedf49e8de05a3430626db3d06d62a32b475549257b031f8e431b0626b7b") )
        ( 750028,   uint256("0x962097c01dc53b1bc9a11c43b9ec09c1aa8d186d6f981e75709622afdaf58ca3") )
        ( 756012,   uint256("0xa30eb8d247955f7f61773e07cb8dd49f610f2a042a113ab7245669f95d528fff") )
        ( 776045,   uint256("0xf4911185e1ed276391097832cc96cfd43c7c300bbc69b677f78880909ff992d1") )
        ( 790078,   uint256("0x8f4cecff69822f79827f2a269b588fdc9a2fe2593a1c49968e63a9e7f97caea0") )
        ( 795011,   uint256("0xd17da70e4abc16fc259d5821d4efb2dd063ca7d82b017a83fb76388b4e6da54e") )
        ( 805098,   uint256("0xa2e8930e2274cafd9672f80a364064a5aceca524a1d79e6890a3782e7f1bc41b") )
        ( 815022,   uint256("0x8ae63b42043201c51b262b4a1960b8526ed8f219b89f1d3f51eb90a46c3b0185") )
        ( 830321,   uint256("0x22165b348586d12706acff1ec68e1e8dc95891bf9196a0753acbbd732d1c5582") )
        ( 845789,   uint256("0x84fa8e75d2720ef3b4d1b2de52adbafa754ef6f88874744b56992bb4c9763126") )
        ( 855123,   uint256("0x7fee5bea51172a2dd98e5f62910638014c1ff50874f3f9de49800a6f33c06afa") )
        ( 876321,   uint256("0x988e813d6924b032d30b9040958f158e1a9ef8d34dd3d154122b1828b0149b73") )
        ( 896456,   uint256("0x118ae8aa218742618ac25d56b1e61dd65933f7409c7ae297094e711710bb28d6") )
        ( 900021,   uint256("0xcd7c8dd3f61c58ca698b07eab0c8a62243e01971b83b4471e6233fca53c388c8") )
        ( 915987,   uint256("0xc5761acfbfa1512a60e0ea416865431a5b474314477352528dad84bd53aa1fc0") )
        ( 935123,   uint256("0x725a3e5cdc9e4fd406d20c06836d266b6804f8e627b229badb1a2f60eddf39da") )
        ( 950753,   uint256("0x0d5c7fc0e875e2546ea7aae9e4cc7224bc65d0f436396012bfc40fd3bcb9e25e") )
        ( 970159,   uint256("0xcd126258d5d4759bbdda5392cfedbc44a3f0f93e1183499381e3549957236a43") )
        ( 990852,   uint256("0xde94e1d720b21b5d29ea74f107cda5426ba2c5b240e0258431a11eaa66c379e1") )
        ( 1010123,   uint256("0x873787d051fd096983a13a8b75b49e05c1c503e410480cae872838efc085215a") )
        ( 1025987,   uint256("0x07e2eceb64909998141167aabae3d3d6d913413286941e6afad2186e700c2ff7") )
        ( 1040456,   uint256("0xdd3c336a817bf3a759017b93b08be80bd736a26287acf0f42441091241fb56c2") )
        ( 1067456,   uint256("0xf774afbf3481cb6d285e96d26b277aae691f1a8f3d6d93957f80d00660c81bbb") )
        ( 1094325,   uint256("0xcfa12b7d744c0f75883afa682b7c349607278a0e6ff029e94160132bd6875fad") )
        ( 1150456,   uint256("0xb189314afc5442a4ae738e331fcbff617faf69a0bd709c50d522369826239e34") )
        ( 1170852,   uint256("0x4f8b0f0245a710c927a3b7d844d5dc097e001c6171b0dd0663850dca2b83f9df") )
        ( 1191654,   uint256("0x34b8f13852587f9bd0cf44b05531474f0ffdc075c7fc3d6c25e6bba39cc9d1ed") )
        ( 1231123,   uint256("0xc8389fa0e6c21f3d53097aa93190396f900c7a82cfe46a652c7640b4773549f6") )
        ( 1260256,   uint256("0x90c9fd34f690fb639a4b7db530850838e5e60fecc6355403a1cc6c6dbac65325") )
    ;

    // TestNet has no checkpoints
    static MapCheckpoints mapCheckpointsTestnet;

    bool CheckHardened(int nHeight, const uint256& hash)
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        if (checkpoints.empty())
            return 0;
        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        MapCheckpoints& checkpoints = (TestNet() ? mapCheckpointsTestnet : mapCheckpoints);

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    // Automatically select a suitable sync-checkpoint 
    const CBlockIndex* AutoSelectSyncCheckpoint()
    {
        const CBlockIndex *pindex = pindexBest;
        // Search backward for a block within max span and maturity window
        while (pindex->pprev && pindex->nHeight + nCheckpointSpan > pindexBest->nHeight)
            pindex = pindex->pprev;
        return pindex;
    }

    // Check against synchronized checkpoint
    bool CheckSync(int nHeight)
    {
        const CBlockIndex* pindexSync = AutoSelectSyncCheckpoint();

        if (nHeight <= pindexSync->nHeight)
            return false;
        return true;
    }
}
