// 472. Concatenated Words
// Problem definition: https://leetcode.com/problems/concatenated-words/
// Accepted ?

#define CATCH_CONFIG_RUNNER
#include "../../uva/catch/catch.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Trie
{
public:
    Trie(const std::vector<std::string>& v) {
        for (const auto& s : v) { insert(s); }
    }

    void insert(const std::string& s) {
        m_root.insert(s.cbegin(), s.cend());
    }

    const bool is_concat(std::string& s) {
        return is_concat(s.begin(), s.end(), m_root, 0);
    }

    struct Node;
    struct Result;

    const bool is_concat(const std::string::iterator& b, const std::string::iterator& e, Node& n, const int count) {
        std::string::iterator current{b};
        Node* activeNode{&n};
        while (current != e) {
            Result r{activeNode->contains_substring(current, e)};
            current = r.last;
            if (r.found) {
                bool substrConcat{is_concat(current, e, m_root, count + 1)};
                if (substrConcat) {
                    return true;
                } else {
                    activeNode = &r.next;
                }
            } else {
                return false;
            }
        }

        return count > 1;
    }

    struct Result
    {
        Result(const bool found, Node& next, const std::string::iterator& last) : found{found}, next{next}, last{last} {}
        const bool found;
        Node& next;
        const std::string::iterator last;
    };

    struct Node
    {
        Node() : c{'\0'}, terminal{false} {}
        Node(const char c) : c{c}, terminal{false} {}

        void insert(const std::string::const_iterator& b, const std::string::const_iterator& e) {
            if (b != e) {
                auto n{next(b)};
                if (n == children.end()) {
                    children.emplace_back(*b);
                    children.rbegin()->insert(b+1, e);
                } else {
                    n->insert(b+1, e);
                }
            } else {
                terminal = true;
            }
        }

        const Result contains_substring(const std::string::iterator& b, const std::string::iterator& e) {
            if (b == e) {
                return Result(true, *this, b);
            } else {
                auto n{next(b)};
                if (n == children.end()) {
                    return Result(false, *this, b);
                } else if (n->terminal) {
                    return Result(true, *n, b + 1);
                } else {
                    return n->contains_substring(b + 1, e);
                }
            }
        }

        const std::vector<Node>::iterator next(const std::string::const_iterator& b) {
            return std::find_if(children.begin(), children.end(), [&b](const Node& n) { return n.c == *b; });
        }

        std::vector<Node> children;
        char c;
        bool terminal;
    };

private:
    Node m_root;
};

class Solution {
public:
    std::vector<std::string> findAllConcatenatedWordsInADict(std::vector<std::string>& words) {
        Trie t{words};
        std::vector<std::string> concat;

        for (auto& s : words) {
            if (t.is_concat(s)) {
                concat.emplace_back(s);
            }
        }

        return concat;
    }
};

int execute(std::istream& in, std::ostream& out) {
    return 0;
}

int main(int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);

    return Catch::Session().run(argc, argv);
    //return execute(std::cin, std::cout);
}

TEST_CASE("Node", "[Concatenated Words]") {
    std::vector<std::string> i{"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};    
    Trie::Node n;
    for (const auto& o : i) { n.insert(o.cbegin(), o.cend()); }

    SECTION("insert") {
        REQUIRE(n.children.size() == 4);
        REQUIRE(n.children[0].c == 'c');
        REQUIRE(n.children[1].c == 'd');
        REQUIRE(n.children[2].c == 'h');
        REQUIRE(n.children[3].c == 'r');
    }
    SECTION("is_substring") {
        std::string s1{"catsdog"};
        Trie::Result r{n.contains_substring(s1.begin(), s1.end())};
        REQUIRE(r.found == true);
        REQUIRE(r.last - s1.begin() == 3);
    }
}

TEST_CASE("Trie", "[Concatenated Words]") {
    std::vector<std::string> i{"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    Trie t{i};
    SECTION("is_concat") {
        std::vector<std::string> o1{"catsdogcats", "dogcatsdog", "ratcatdogcat"};
        for (auto& s : o1) {
            REQUIRE(t.is_concat(s) == true);
        }
        std::vector<std::string> o2{"catsdogcats1", "dogcatsdog2", "ratcatdogcat3"};
        for (auto& s : o2) {
            REQUIRE(t.is_concat(s) == false);
        }
        std::vector<std::string> o3{"cat", "cats", "dog", "rat", "hippopotamuses"};
        for (auto& s : o3) {
            REQUIRE(t.is_concat(s) == false);
        }
    }
}

TEST_CASE("Execute unit tests", "[Concatenated Words]") {
    std::vector<std::string> i{"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
    std::vector<std::string> o{"catsdogcats", "dogcatsdog", "ratcatdogcat"};
    Solution s;
    REQUIRE(s.findAllConcatenatedWordsInADict(i) == o);
}

TEST_CASE("LeetCode test cases", "[Concatenated Words]") {
    std::vector<std::string> i{"rfkqyuqfjkx","","vnrtysfrzrmzl","gfve","qfpd","lqdqrrcrwdnxeuo","q","klaitgdphcspij","hbsfyfv",
        "adzpbfudkklrw","aozmixr","ife","feclhbvfuk","yeqfqojwtw","sileeztxwjl","ngbqqmbxqcqp","khhqr","dwfcayssyoqc","omwufbdfxu",
        "zhift","kczvhsybloet","crfhpxprbsshsjxd","ilebxwbcto","yaxzfbjbkrxi","imqpzwmshlpj","ta","hbuxhwadlpto","eziwkmg",
        "ovqzgdixrpddzp","c","wnqwqecyjyib","jy","mjfqwltvzk","tpvo","phckcyufdqml","lim","lfz","tgygdt","nhcvpf","fbrpzlk",
        "shwywshtdgmb","bkkxcvg","monmwvytby","nuqhmfj","qtg","cwkuzyamnerp","fmwevhwlezo","ye","hbrcewjxvcezi","tiq","tfsrptug",
        "iznorvonzjfea","gama","apwlmbzit","s","hzkosvn","nberblt","kggdgpljfisylt","mf","h","bljvkypcflsaqe","cijcyrgmqirz",
        "iaxakholawoydvch","e","gttxwpuk","jf","xbrtspfttota","sngqvoijxuv","bztvaal","zxbshnrvbykjql","zz","mlvyoshiktodnsjj",
        "qplci","lzqrxl","qxru","ygjtyzleizme","inx","lwhhjwsl","endjvxjyghrveu","phknqtsdtwxcktmw","wsdthzmlmbhjkm","u","pbqurqfxgqlojmws",
        "mowsjvpvhznbsi","hdkbdxqg","ge","pzchrgef","ukmcowoe","nwhpiid","xdnnl","n","yjyssbsoc","cdzcuunkrf","uvouaghhcyvmlk",
        "aajpfpyljt","jpyntsefxi","wjute","y","pbcnmhf","qmmidmvkn","xmywegmtuno","vuzygv","uxtrdsdfzfssmel","odjgdgzfmrazvnd","a",
        "rdkugsbdpawxi","ivd","bbqeonycaegxfj","lrfkraoheucsvpi","eqrswgkaaaohxx","hqjtkqaqh","berbpmglbjipnuj","wogwczlkyrde","aqufowbig",
        "snjniegvdvotu","ocedkt","bbufnxorixibbd","rzuqsyr","qghoy","evcuanuujszitaoa","wsx","glafbwzdd","znrvjqeyqi","npitruijvyllsi",
        "objltu","ryp","nvybsfrxtlfmp","id","zoolzslgd","owijatklvjzscizr","upmsoxftumyxifyu","xucubv","fctkqlroq","zjv","wzi","ppvs",
        "mflvioemycnphfjt","nwedtubynsb","repgcx","gsfomhvpmy","kdohe","tyycsibbeaxn","wjkfvabn","llkmagl","thkglauzgkeuly",
        "paeurdvexqlw","akdt","ihmfrj","janxk","rqdll","cyhbsuxnlftmjc","yybwsjmajbwtuhkk","ovytgaufpjl","iwbnzhybsx","mumbh","jqmdabmyu",
        "br","lwstjkoxbczkj","vhsgzvwiixxaob","fso","qnebmfl","ooetjiz","lq","msxphqdgz","mqhoggvrvjqrp","xbhkkfg","zxjegsyovdrmw","jav",
        "mshoj","ax","biztkfomz","hujdmcyxdqteqja","gqgsomonv","reqqzzpw","lihdnvud","lznfhbaokxvce","fhxbldylqqewdnj","rlbskqgfvn",
        "lfvobeyolyy","v","iwh","fpbuiujlolnjl","gvwxljbo","ypaotdzjxxrsc","mwrvel","umzpnoiei","ogwilaswn","yw","egdgye","hsrznlzrf",
        "mwdgxaigmxpy","yaqgault","dtlg","cyvfiykmkllf","zxqyhvizqmamj","lvvgoifltzywueyp","abinmy","ppzaecvmx","qsmzc","iddymnl",
        "uskihek","evxtehxtbthq","jvtfzddlgch","czohpyewf","ufzazyxtqxcu","brxpfymuvfvs","xrrcfuusicc","aqhlswbzievij","rv","udvmara",
        "upityz","fecd","suxteeitxtg","dfuydrtbfypbn","cypqodxr","wikfuxwjht","jrliuaifpp","vkmxys","wvpfyfpkvgthq","rmajxis","jncxgviyu",
        "av","nmhskodmidaj","lkfrimprrhen","uip","hstyopbvuiqc","p","vwduwmjpblqo","fnxwgqtvwztje","xwnbcuggl","iehimvoymyjasin","spsqiu",
        "flhyfac","mqrbq","pstsxhplrrmbeddv","hnegtuxx","alsyxezjwtlwmxv","jtxytykkcku","bhhlovgcx","xhhivxnutkx","had","aysulvk","m",
        "anhsyxli","jdkgfc","potn","lcibpxkidmwexp","gwoxjicdkv","tltienw","ngiutnuqbzi","o","tzlyb","vumnwehj","os","np","lhv","uzvgyeette",
        "ipfvr","lpprjjalchhhcmh","k","pciulccqssaqgd","tp","dmzdzveslyjad","wtsbhgkd","eouxbldsxzm","vhtonlampljgzyve","xhnlcrldtfthul",
        "xhflc","upgei","rlaks","yfqvnvtnqspyjbxr","phouoyhvls","voibuvbhhjcdflvl","rgorfbjrofokggaf","dqhqats","zchpicyuawpovm","yzwfor",
        "koat","pybf","fhdzsbiyjld","gznfnqydisn","xz","po","tcjup","wygsnxk","kqlima","fgxnuohrnhg","publurhztntgmimc","zuufzphd",
        "iucrmmmjqtcey","wnnbq","rghzyz","ukjqsjbmp","mdtrgv","vyeikgjdnml","kxwldnmi","apzuhsbssaxj","tkbkoljyodlipof","nkq","ktwtj",
        "vgmkgjwle","t","agylw","vomtuy","jbtvitkqn","vtdxwrclpspcn","rdrls","yxfeoh","upj","myctacn","fdnor","ahqghzhoqprgkym","phiuvdv",
        "jp","fdgpouzjwbq","hqoyefmugjvewhxu","qfzwuwe","fnsbijkeepyxry","oja","qthkcij","zpmqfbmnr","ybaibmzonzqlnmd","svo","gjftyfehik",
        "jfrfgznuaytvaegm","aljhrx","odjq","ogwaxrssjxgvnka","zaqswwofedxj","lugpktauixp","dc","odknlbvxrs","jeobu","vqythyvzxbcgrlbg",
        "hwc","erpbaxq","ujxcxck","rrklkb","wlrwyuy","zmg","yyhga","xwdbycdu","htedgvsrhchox","wr","suhesetv","jonqwhkwezjvjgg",
        "sqqyrxtjkcalswq","hvyimhe","pjzdkmoue","zbphmgoxq","lbdlcumdgixjbcq","ztzdjqmadthtdmv","qcagsyqggcf","if","jpjxcjyi",
        "chyicqibxdgkqtg","iwpdklhum","wljmg","micmun","npdbamofynykqv","ijsnfkpfy","lmq","oyjmeqvhcrvgm","mqopusqktdthpvz","fz","r",
        "qbsqtipq","nxtsnason","xbpipyhh","topsuqomfjrd","islif","gbndakaq","bwnkxnwpzeoohlx","hrtbfnq","fguvomeepxoffg","mat","dzfpfnwbfuj",
        "onlvy","cwcchvsasdylb","rxfcztzqopdi","ybrhodjn","oqkijy","ncvrjo","dphbfaal","xgtpdtkz","sebevsopjvciwljf","rcumyacqdapwczen",
        "mabkapuoud","pbozezeygljfftvy","bvazmzbndl","vl","qiaixdtbhqvlzd","ffjfb","svthrfmkoxbho","cvet","ucgqyvopafyttrh","lbgihet",
        "naiqyufxffdw","vruh","uz","ukffmudygjavem","dccamymhp","wofwgjkykm","fbuujzxhln","kmm","lzandlltowjpwsal","fapfvrmezbsjxs",
        "wiw","sc","soqlh","hzaplclkwl","gcdqbcdwbwa","gadgt","pgowefka","juffuguqepwnfh","nbuinl","cpdxf","sox","fq","lfnrhgsxkhx",
        "xrcorfygjxpi","mwtqjwbhgh","loc","fkglorkkvx","nlzdhucvayrz","azefobxutitrf","rlrstkcbtikklmh","ggk","sbphcejuylh","nraoenhd",
        "zngyodiqlchxyycx","rrbhfwohfv","krzolrglgn","cpjesdzy","yoifoyg","hqqevqjugi","ahmv","xgaujnyclcjq","evhyfnlohavrj","byyvhgh",
        "hyw","kedhvwy","ysljsqminajfipds","rglnpxfqwu","cibpynkxg","su","mbntqrlwyampdg","nig","ldhlhqdyjcfhu","jfymrbafmyoc","tyjmnhlfnrtz",
        "dlazixtlxyvm","fbiguhsfuqo","rhymsno","rkbdlchs","ocbbwwd","astaiamnepwkya","mplirup","edkxjq","g","exlwulswtvot","tlnc","vnrrzerz",
        "ygeraoozbtt","yyifkin","eo","ua","qgztvqdolf","rlzddjzcshvd","khxkdxflwxme","kk","zylbhoaac","cw","iizic","gcdxstpz","kjwdqeg",
        "earjrncmmkdel","kbesuhquepj","nrzbllldgdmyrpgl","hllwnqozf","djpchowhwevbqvjj","zsmhylnjpktb","pxnktxkm","fxwiaqqb","qjwufmwresfsfaok",
        "aa","d","iobioqm","svjgzk","khbzp","euexyudhrioi","yqsj","ngrwqpoh","rwuvd","eruffmlg","bxzovyew","faz","pmvfvyguqdi","jlxnoixsy",
        "hyfrdngjf","ly","eibcapetpmeaid","tpnwwiif","pfgsp","kvhhwkzvtvlhhb","pjxurgqbtldims","rncplkeweoirje","akyprzzphew","wyvfpjyglzrmhfqp",
        "ubheeqt","rmbxlcmn","taqakgim","apsbu","khwnykughmwrlk","vtdlzwpbhcsbvjno","tffmjggrmyil","schgwrrzt","mvndmua","nlwpw","glvbtkegzjs",
        "piwllpgnlpcnezqs","xkelind","urtxsezrwz","zechoc","vfaimxrqnyiq","ybugjsblhzfravzn","btgcpqwovwp","zgxgodlhmix","sfzdknoxzassc",
        "wgzvqkxuqrsqxs","dwneyqisozq","fg","vhfsf","uspujvqhydw","eadosqafyxbmzgr","tyff","blolplosqnfcwx","uwkl","puenodlvotb","iizudxqjvfnky",
        "cjcywjkfvukvveq","jrxd","igwb","dftdyelydzyummmt","uvfmaicednym","oai","higfkfavgeemcgo","naefganqo","iqebfibigljbc","ulicojzjfrc",
        "igxprunj","cymbrl","fqmwciqtynca","zjyagi","mzuejrttefhdwqc","zyiurxvf","wrjxffzbjexsh","wrxw","mhrbdxjwi","htknfa","wfrvxqdkhbwwef",
        "vqsghhhutdget","cwupzrts","hbjnb","wpccoa","nx","howbzhaoscgyk","bilt","wqqatye","zceuuwg","jxzon","kkfj","bwsezd","ifdegsyjtswselk",
        "xweimxlnzoh","tqthlftjblnpht","ww","ss","b","jmruuqscwjp","nxbk","wd","cqkrtbxgzg","xhppcjnq","cfq","tkkolzcfi","wblxki","ijeglxsvc",
        "kcqjjwcwuhvzydm","gubqavlqffhrzz","hiwxrgftittd","caybc","ncsyjlzlxyyklc","poxcgnexmaajzuha","dhaccuualacyl","mtkewbprs","oncggqvr",
        "sqqoffmwkplsgbrp","ioajuppvqluhbdet","dzwwzaelmo","afumtqugec","wglucmugwqi","zveswrjevfz","nxlbkak","pzcejvxzeoybb","fd","vewj",
        "ivws","zjhudtpqsfc","zcmukotirrxx","zksmx","umofzhhowyftz","zbotrokaxaryxlk","ueolqk","dxmzhoq","zvu","cjl","esfmqgvxwfy","npbep",
        "vbgjtbv","poeugoqynkbfiv","fewjjscjrei","yqssxzsydgllfzmo","urxkwcypctjkabi","wqtldwhjouas","tovdtkr","onzgeyddkqwuhnim","ffxviyvsktqrfa",
        "qujhd","pvcz","hiyjlkxmeplnrvxg","hdykehkefp","vepcxhozpjxtreyn","liguhuxudbnh","f","ordxzm","klgohcmmbukz","yrmooliaobbnlap",
        "dutnbetocxylcey","ywdsjegd","cr","blbxhjsgcuoxmqft","ngzdc","srfyjjumcbxole","dazwzwtdjoyuqeqj","xazjarqgfm","fxyfqbeoktcc","qrsjchxp",
        "iltaqzawhgu","sgenjcfxr","yfikp","dvwhbyumthkiktb","walsx","jyajrkcvysicisab","brdeumb","tviihjwxdcz","dnrrgmem","ydgxlrjzucxyid",
        "cdvdpvjlagwmg","ngnpxjkxims","gvyhnchlimsxc","w","jtizpezjl","qe","rjzv","vhnqvi","qm","iedzqswrsnfmnn","lt","utqfcqyrrwm","wtelvsqrru",
        "fjwrhjcrtbcytn","qmqxceuohpiffaq","rmoybqjjgdyo","pmxttqftypfexlv","tg","qa","iqbqjlnpbf","kgaynkddbzllecd","tccvslp","curkxfoimnw",
        "fvnyqkzlheruxr","iiygnzfov","coqs","oa","eiu","vzemmxtklis","lxu","nrwsjaxzwmh","tdayz","oxbbemejgosgcynf","ykbcn","hesvnctfvdsp",
        "ku","rjhykpadahbhj","at","sxlngbtxmqr","wqrom","qzyabzrco","rbbyklndcqdj","cnsmgmwmpbgjq","krvnaf","qrwfajnfahyqocdb","fnlaozmff",
        "vmoymbmytjvfcgt","cijyy","jdgwjbztl","swmalgbgpaplqgz","hfl","typttkrpfvx","tkzpzrscwbx","bwfqqvjcukjbsg","nxqmxr","x","eyavnz",
        "il","dhthp","eyelg","npsoqsw","reogbmveofvusdsx","jvdrjkhxkq","qzjbrpljwuzpl","czqeevvbvcwh","vzuszqvhlmapty","yu","yldwwgezlqur",
        "vorxwgdtgjilgydq","pknt","bgihl","ckorgrm","ixylxjmlfv","bpoaboylced","zea","igfagitkrext","ipvqq","dmoerc","oqxbypihdv",
        "dtjrrkxro","rexuhucxpi","bvmuyarjwqpcoywa","qwdmfpwvamisns","bhopoqdsref","tmnm","cre","ktrniqwoofoeenbz","vlrfcsftapyujmw","updqikocrdyex",
        "bcxw","eaum","oklsqebuzeziisw","fzgyhvnwjcns","dybjywyaodsyw","lmu","eocfru","ztlbggsuzctoc","ilfzpszgrgj","imqypqo","fump",
        "sjvmsbrcfwretbie","oxpmplpcg","wmqigymr","qevdyd","gmuyytguexnyc","hwialkbjgzc","lmg","gijjy","lplrsxznfkoklxlv","xrbasbznvxas","twn",
        "bhqultkyfq","saeq","xbuw","zd","kng","uoay","kfykd","armuwp","gtghfxf","gpucqwbihemixqmy","jedyedimaa","pbdrx","toxmxzimgfao","zlteob",
        "adoshnx","ufgmypupei","rqyex","ljhqsaneicvaerqx","ng","sid","zagpiuiia","re","oadojxmvgqgdodw","jszyeruwnupqgmy","jxigaskpj","zpsbhgokwtfcisj",
        "vep","ebwrcpafxzhb","gjykhz","mfomgxjphcscuxj","iwbdvusywqlsc","opvrnx","mkgiwfvqfkotpdz","inpobubzbvstk","vubuucilxyh","bci","dibmye",
        "rlcnvnuuqfvhw","oorbyyiigppuft","swpksfdxicemjbf","goabwrqdoudf","yjutkeqakoarru","wuznnlyd","vfelxvtggkkk","mxlwbkbklbwfsvr","advraqovan",
        "smkln","jxxvzdjlpyurxpj","ssebtpznwoytjefo","dynaiukctgrzjx","irzosjuncvh","hcnhhrajahitn","vwtifcoqepqyzwya","kddxywvgqxo","syxngevs",
        "batvzmziq","mjewiyo","pzsupxoflq","byzhtvvpj","cqnlvlzr","akvmxzbaei","mwo","vg","ekfkuajjogbxhjii","isdbplotyak","jvkmxhtmyznha","lqjnqzrwrmgt",
        "mbbhfli","bpeohsufree","ajrcsfogh","lucidbnlysamvy","tutjdfnvhahxy","urbrmmadea","hghv","acnjx","athltizloasimp","gu","rjfozvgmdakdhao","iephs",
        "uztnpqhdl","rfuyp","crcszmgplszwfn","zihegt","xbspa","cjbmsamjyqqrasz","ghzlgnfoas","ljxl","cnumquohlcgt","jm","mfccj","hfedli","vtpieworwhyiucs",
        "tdtuquartspkotm","pnkeluekvelj","ugrloq","zljmwt","fkyvqguqq","tpjidglpxqfxv","l","tvvimvroz","yy","opwyfovdz","pwlumocnyuoume","vjqpzkcfc",
        "ihicd","dtttiixlhpikbv","goblttgvmndkqgg","gwsibcqahmyyeagk","prtvoju","lcblwidhjpu","kbu","pey","gkzrpc","bqajopjjlfthe","bc","lqs",
        "zkndgojnjnxqsoqi","zyesldujjlp","drswybwlfyzph","xzluwbtmoxokk","bedrqfui","opajzeahv","lehdfnr","mnlpimduzgmwszc","velbhj","miwdn","wruqc",
        "kscfodjxg","wcbm"};
    std::string s1{"velbhj"};
    std::string s2{"bedrqfui"};
    Trie t{i};
    REQUIRE(t.is_concat(s1) == false);
    REQUIRE(t.is_concat(s2) == false);
}

/* 
Observed: ["gfve","qfpd","lqdqrrcrwdnxeuo","hbsfyfv","ife","feclhbvfuk","ngbqqmbxqcqp","khhqr","dwfcayssyoqc","omwufbdfxu","ilebxwbcto","ta","hbuxhwadlpto","mjfqwltvzk","tpvo","phckcyufdqml","lim","lfz","tgygdt","nhcvpf","shwywshtdgmb","bkkxcvg","monmwvytby","nuqhmfj","qtg","cwkuzyamnerp","fmwevhwlezo","ye","tiq","tfsrptug","gama","nberblt","mf","gttxwpuk","xbrtspfttota","qplci","qxru","phknqtsdtwxcktmw","pbqurqfxgqlojmws","hdkbdxqg","ge","ukmcowoe","xdnnl","yjyssbsoc","uvouaghhcyvmlk","aajpfpyljt","jpyntsefxi","pbcnmhf","qmmidmvkn","xmywegmtuno","vuzygv","uxtrdsdfzfssmel","rdkugsbdpawxi","bbqeonycaegxfj","lrfkraoheucsvpi","eqrswgkaaaohxx","aqufowbig","ocedkt","qghoy","wsx","glafbwzdd","ryp","nvybsfrxtlfmp","upmsoxftumyxifyu","xucubv","fctkqlroq","wzi","ppvs","nwedtubynsb","repgcx","gsfomhvpmy","kdohe","llkmagl","thkglauzgkeuly","paeurdvexqlw","akdt","rqdll","ovytgaufpjl","mumbh","br","fso","qnebmfl","lq","msxphqdgz","xbhkkfg","mshoj","ax","gqgsomonv","reqqzzpw","fhxbldylqqewdnj","rlbskqgfvn","lfvobeyolyy","mwrvel","ogwilaswn","yw","egdgye","yaqgault","dtlg","qsmzc","iddymnl","evxtehxtbthq","brxpfymuvfvs","rv","udvmara","fecd","dfuydrtbfypbn","cypqodxr","vkmxys","wvpfyfpkvgthq","av","nmhskodmidaj","uip","vwduwmjpblqo","xwnbcuggl","spsqiu","flhyfac","mqrbq","pstsxhplrrmbeddv","hnegtuxx","bhhlovgcx","had","aysulvk","anhsyxli","potn","vumnwehj","os","np","lhv","uzvgyeette","tp","wtsbhgkd","eouxbldsxzm","xhnlcrldtfthul","xhflc","upgei","rlaks","phouoyhvls","dqhqats","koat","pybf","xz","po","wygsnxk","kqlima","fgxnuohrnhg","wnnbq","mdtrgv","kxwldnmi","nkq","ktwtj","agylw","vomtuy","vtdxwrclpspcn","rdrls","yxfeoh","upj","myctacn","fdnor","qfzwuwe","oja","qthkcij","svo","odjq","dc","odknlbvxrs","hwc","erpbaxq","rrklkb","wlrwyuy","yyhga","xwdbycdu","htedgvsrhchox","wr","suhesetv","qcagsyqggcf","wljmg","npdbamofynykqv","lmq","oyjmeqvhcrvgm","mqopusqktdthpvz","fz","nxtsnason","gbndakaq","hrtbfnq","fguvomeepxoffg","mat","onlvy","cwcchvsasdylb","ybrhodjn","ncvrjo","dphbfaal","xgtpdtkz","mabkapuoud","vl","ffjfb","svthrfmkoxbho","cvet","ucgqyvopafyttrh","vruh","uz","ukffmudygjavem","dccamymhp","kmm","wiw","sc","soqlh","gcdqbcdwbwa","gadgt","pgowefka","cpdxf","sox","fq","lfnrhgsxkhx","loc","fkglorkkvx","nlzdhucvayrz","ggk","nraoenhd","rrbhfwohfv","yoifoyg","ahmv","evhyfnlohavrj","byyvhgh","hyw","kedhvwy","rglnpxfqwu","su","mbntqrlwyampdg","nig","jfymrbafmyoc","tyjmnhlfnrtz","rhymsno","rkbdlchs","ocbbwwd","edkxjq","exlwulswtvot","tlnc","yyifkin","eo","ua","khxkdxflwxme","kk","cw","gcdxstpz","kbesuhquepj","pxnktxkm","aa","khbzp","yqsj","ngrwqpoh","rwuvd","eruffmlg","bxzovyew","faz","pmvfvyguqdi","hyfrdngjf","ly","pfgsp","akyprzzphew","ubheeqt","rmbxlcmn","taqakgim","apsbu","khwnykughmwrlk","schgwrrzt","mvndmua","nlwpw","btgcpqwovwp","sfzdknoxzassc","fg","vhfsf","tyff","blolplosqnfcwx","uwkl","puenodlvotb","oai","naefganqo","cymbrl","wrxw","htknfa","wfrvxqdkhbwwef","vqsghhhutdget","wpccoa","nx","bilt","wqqatye","kkfj","bwsezd","ww","ss","jmruuqscwjp","nxbk","wd","cqkrtbxgzg","cfq","wblxki","gubqavlqffhrzz","caybc","dhaccuualacyl","mtkewbprs","oncggqvr","sqqoffmwkplsgbrp","afumtqugec","wglucmugwqi","nxlbkak","fd","vewj","umofzhhowyftz","ueolqk","cjl","esfmqgvxwfy","npbep","poeugoqynkbfiv","yqssxzsydgllfzmo","tovdtkr","pvcz","hdykehkefp","ordxzm","klgohcmmbukz","dutnbetocxylcey","cr","ngzdc","fxyfqbeoktcc","walsx","brdeumb","dnrrgmem","gvyhnchlimsxc","qe","vhnqvi","qm","lt","utqfcqyrrwm","wtelvsqrru","qmqxceuohpiffaq","pmxttqftypfexlv","tg","qa","tccvslp","coqs","oa","eiu","lxu","tdayz","ykbcn","hesvnctfvdsp","ku","at","sxlngbtxmqr","wqrom","rbbyklndcqdj","cnsmgmwmpbgjq","krvnaf","swmalgbgpaplqgz","hfl","typttkrpfvx","nxqmxr","eyavnz","dhthp","eyelg","npsoqsw","reogbmveofvusdsx","yu","pknt","ckorgrm","bpoaboylced","dmoerc","rexuhucxpi","bhopoqdsref","tmnm","cre","vlrfcsftapyujmw","bcxw","eaum","dybjywyaodsyw","lmu","eocfru","fump","oxpmplpcg","qevdyd","gmuyytguexnyc","lmg","lplrsxznfkoklxlv","twn","bhqultkyfq","saeq","xbuw","kng","uoay","kfykd","armuwp","gtghfxf","pbdrx","adoshnx","ufgmypupei","rqyex","ng","sid","re","vep","ebwrcpafxzhb","gjykhz","mfomgxjphcscuxj","opvrnx","vubuucilxyh","bci","rlcnvnuuqfvhw","goabwrqdoudf","wuznnlyd","vfelxvtggkkk","mxlwbkbklbwfsvr","advraqovan","smkln","kddxywvgqxo","syxngevs","akvmxzbaei","mwo","vg","mbbhfli","bpeohsufree","lucidbnlysamvy","urbrmmadea","hghv","acnjx","gu","uztnpqhdl","rfuyp","xbspa","cnumquohlcgt","mfccj","hfedli","tdtuquartspkotm","pnkeluekvelj","ugrloq","fkyvqguqq","yy","opwyfovdz","pwlumocnyuoume","goblttgvmndkqgg","prtvoju","lcblwidhjpu","kbu","pey","bc","lqs","xzluwbtmoxokk","bedrqfui","lehdfnr","velbhj","wruqc","wcbm"]
Expected: ["gfve","qfpd","lqdqrrcrwdnxeuo","hbsfyfv","ife","feclhbvfuk","ngbqqmbxqcqp","khhqr","dwfcayssyoqc","omwufbdfxu","ilebxwbcto","ta","hbuxhwadlpto","tpvo","phckcyufdqml","lfz","tgygdt","nhcvpf","shwywshtdgmb","bkkxcvg","monmwvytby","qtg","cwkuzyamnerp","ye","tfsrptug","gama","nberblt","mf","gttxwpuk","xbrtspfttota","qxru","phknqtsdtwxcktmw","pbqurqfxgqlojmws","hdkbdxqg","ge","ukmcowoe","xdnnl","yjyssbsoc","uvouaghhcyvmlk","pbcnmhf","qmmidmvkn","xmywegmtuno","vuzygv","uxtrdsdfzfssmel","eqrswgkaaaohxx","ocedkt","qghoy","wsx","glafbwzdd","ryp","nvybsfrxtlfmp","upmsoxftumyxifyu","xucubv","fctkqlroq","ppvs","nwedtubynsb","repgcx","gsfomhvpmy","kdohe","llkmagl","thkglauzgkeuly","paeurdvexqlw","akdt","rqdll","mumbh","br","fso","qnebmfl","lq","xbhkkfg","ax","gqgsomonv","reqqzzpw","rlbskqgfvn","lfvobeyolyy","mwrvel","ogwilaswn","yw","egdgye","yaqgault","dtlg","iddymnl","evxtehxtbthq","brxpfymuvfvs","rv","udvmara","fecd","dfuydrtbfypbn","cypqodxr","vkmxys","wvpfyfpkvgthq","av","vwduwmjpblqo","xwnbcuggl","flhyfac","mqrbq","pstsxhplrrmbeddv","hnegtuxx","bhhlovgcx","had","aysulvk","potn","os","np","lhv","uzvgyeette","tp","wtsbhgkd","eouxbldsxzm","xhnlcrldtfthul","xhflc","rlaks","phouoyhvls","dqhqats","koat","pybf","po","wygsnxk","kqlima","fgxnuohrnhg","wnnbq","mdtrgv","nkq","agylw","vomtuy","vtdxwrclpspcn","rdrls","yxfeoh","myctacn","fdnor","qfzwuwe","svo","dc","odknlbvxrs","hwc","erpbaxq","rrklkb","wlrwyuy","yyhga","xwdbycdu","htedgvsrhchox","wr","suhesetv","qcagsyqggcf","wljmg","npdbamofynykqv","lmq","oyjmeqvhcrvgm","nxtsnason","gbndakaq","hrtbfnq","fguvomeepxoffg","mat","onlvy","cwcchvsasdylb","dphbfaal","mabkapuoud","vl","ffjfb","svthrfmkoxbho","cvet","ucgqyvopafyttrh","vruh","ukffmudygjavem","dccamymhp","kmm","sc","soqlh","gcdqbcdwbwa","gadgt","pgowefka","cpdxf","sox","fq","lfnrhgsxkhx","loc","fkglorkkvx","ggk","nraoenhd","rrbhfwohfv","yoifoyg","ahmv","byyvhgh","hyw","kedhvwy","rglnpxfqwu","su","mbntqrlwyampdg","jfymrbafmyoc","rhymsno","rkbdlchs","ocbbwwd","exlwulswtvot","tlnc","eo","ua","khxkdxflwxme","kk","cw","pxnktxkm","aa","ngrwqpoh","rwuvd","eruffmlg","bxzovyew","hyfrdngjf","ly","pfgsp","akyprzzphew","ubheeqt","rmbxlcmn","apsbu","khwnykughmwrlk","mvndmua","nlwpw","btgcpqwovwp","sfzdknoxzassc","fg","vhfsf","tyff","blolplosqnfcwx","uwkl","puenodlvotb","naefganqo","cymbrl","wrxw","htknfa","wfrvxqdkhbwwef","vqsghhhutdget","wpccoa","nx","bilt","wqqatye","bwsezd","ww","ss","jmruuqscwjp","nxbk","wd","cfq","gubqavlqffhrzz","caybc","dhaccuualacyl","mtkewbprs","oncggqvr","sqqoffmwkplsgbrp","afumtqugec","nxlbkak","fd","ueolqk","esfmqgvxwfy","npbep","yqssxzsydgllfzmo","tovdtkr","hdykehkefp","ordxzm","dutnbetocxylcey","cr","ngzdc","fxyfqbeoktcc","walsx","brdeumb","dnrrgmem","gvyhnchlimsxc","qe","qm","lt","utqfcqyrrwm","wtelvsqrru","qmqxceuohpiffaq","pmxttqftypfexlv","tg","qa","tccvslp","coqs","oa","lxu","ykbcn","hesvnctfvdsp","ku","at","sxlngbtxmqr","wqrom","krvnaf","hfl","typttkrpfvx","nxqmxr","dhthp","eyelg","npsoqsw","reogbmveofvusdsx","yu","pknt","ckorgrm","bpoaboylced","dmoerc","bhopoqdsref","tmnm","cre","vlrfcsftapyujmw","bcxw","eaum","dybjywyaodsyw","lmu","eocfru","fump","oxpmplpcg","qevdyd","gmuyytguexnyc","lmg","lplrsxznfkoklxlv","twn","bhqultkyfq","saeq","xbuw","kng","uoay","kfykd","armuwp","gtghfxf","pbdrx","adoshnx","rqyex","ng","sid","re","vep","ebwrcpafxzhb","opvrnx","vubuucilxyh","rlcnvnuuqfvhw","goabwrqdoudf","wuznnlyd","vfelxvtggkkk","mxlwbkbklbwfsvr","advraqovan","smkln","kddxywvgqxo","syxngevs","mwo","vg","bpeohsufree","lucidbnlysamvy","urbrmmadea","hghv","gu","uztnpqhdl","rfuyp","xbspa","cnumquohlcgt","tdtuquartspkotm","ugrloq","fkyvqguqq","yy","pwlumocnyuoume","goblttgvmndkqgg","lcblwidhjpu","kbu","pey","bc","lqs","xzluwbtmoxokk","lehdfnr","wruqc","wcbm"]
*/