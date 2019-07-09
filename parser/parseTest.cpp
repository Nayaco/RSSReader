#include "channel.h"
#include "item.h"
#include "RSSparser.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    static const char* xml =
    "<?xml version=\"1.0\" encoding=\"utf-8\" ?>"
    "<rss>"
        "<channel>"
            "<title>"
                "<![CDATA[ bilibili 3日排行榜-动画-近期投稿 ]]>"
            "</title>"
            "<link>https://www.bilibili.com/ranking/all/0/0/3</link>"
            "<description>"
                "<![CDATA["
                "bilibili 3日排行榜-动画-近期投稿 - Made with love by RSSHub(https://github.com/DIYgod/RSSHub)"
                "]]>"
            "</description>"
            "<generator>RSSHub</generator>"
            "<webMaster>i@diygod.me</webMaster>"
            "<language>zh-cn</language>"
            "<lastBuildDate>Tue, 09 Jul 2019 13:23:58 GMT</lastBuildDate>"
            "<ttl>30</ttl>"
            "<item>"
                "<title>"
                    "<![CDATA[ 罗汉鬼套路：lol一个不被秒就死不了的套路 万鞭归宗！！！ ]]>"
                "</title>"
                "<description>"
                    "<![CDATA["
                    "作者：罗汉解说<br>播放量：2364720<br>时长：8:21<br>综合得分：3225431<br>弹幕：12691<br><img referrerpolicy=\"no-referrer\" src=\"http://i0.hdslb.com/bfs/archive/2f84e5f00f8258b1e7363cd0d5e3da2374ff3cdc.jpg\">"
                    "]]>"
                "</description>"
                "<guid>https://www.bilibili.com/video/av58130411</guid>"
                "<link>https://www.bilibili.com/video/av58130411</link>"
            "</item>"
            "<item>"
                "<title>"
                    "<![CDATA[ 【赵本山】Bad Guy ]]>"
                "</title>"
                "<description>"
                    "<![CDATA["
                    "作者：大烩员<br>播放量：1244671<br>时长：2:37<br>综合得分：1674484<br>弹幕：14584<br><img referrerpolicy=\"no-referrer\" src=\"http://i1.hdslb.com/bfs/archive/60e7aa8f76463280815480249ce200bb364165b4.jpg\">"
                    "]]>"
                "</description>"
                "<guid>https://www.bilibili.com/video/av58149114</guid>"
                "<link>https://www.bilibili.com/video/av58149114</link>"
            "</item>"
        "</channel>"
    "</rss>"
    "</entries>";
    RSSParser parser;
    parser.SetDoc(xml);
    auto chan = parser.Parse();
    cout<<chan->GetTitle()<<endl;
    cout<<chan->GetLink()<<endl;
    cout<<chan->GetDesc()<<endl;
    auto &items = chan->GetItems();
    for(auto i: items) {
        cout<<"--item--"<<endl;
        cout<<i->GetTitle()<<endl;
        cout<<i->GetLink()<<endl;
        cout<<i->GetDesc()<<endl;
        cout<<"--------"<<endl;
    }
    return 0;
}
