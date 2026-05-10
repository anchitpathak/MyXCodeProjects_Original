#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;

class ISubscriber;
class IChannel
{
public:
    virtual void subscribe(ISubscriber* sub) = 0;
    virtual void unSubscribe(ISubscriber* sub) = 0;
    virtual void notifySubscriber() = 0;
    virtual void uploadVideo(const string& vName) = 0;
    virtual void watchVideo() = 0;
    virtual ~IChannel() = default;
};

class ISubscriber
{
public:
    virtual void update(IChannel* channel) = 0;
    virtual void subscribeChannel(IChannel* channel) = 0;
    virtual ~ISubscriber() = default;
};

class Channel : public IChannel
{
    string channelName;
    string latestVideo;
    vector<ISubscriber*> subscriberList;

public:
    Channel(const string &name) : channelName(name) {}

    void subscribe(ISubscriber* sub) override
    {
        if(find(subscriberList.begin(), subscriberList.end(), sub) == subscriberList.end())
        {
            subscriberList.push_back(sub);
            cout << "New subscriber added to " << channelName << endl;
        }
        else
        {
            cout << "Subscriber already exists in " << channelName << endl;
        }
    }

    void unSubscribe(ISubscriber* sub) override
    {
        auto it = find(subscriberList.begin(), subscriberList.end(), sub);
        if(it != subscriberList.end())
        {
            subscriberList.erase(it);
            cout << "Subscriber removed from " << channelName << endl;
        }
    }

    void notifySubscriber() override
    {
        for(ISubscriber* sub : subscriberList)
        {
            sub->update(this);
        }
    }

    void uploadVideo(const string& vName) override
    {
        latestVideo = vName;
        cout << "New video \"" << latestVideo << "\" uploaded on " << channelName << endl;
        notifySubscriber();
    }

    void watchVideo() override
    {
        cout << "\"" << latestVideo << "\" is being watched on channel \"" << channelName << "\"" << endl;
    }
};

class Subscriber : public ISubscriber
{
    string subsName;
public:
    Subscriber(const string& name) : subsName(name) {}

    void update(IChannel* channel) override
    {
        cout << subsName << " got notified: ";
        channel->watchVideo();
    }

    void subscribeChannel(IChannel* channel) override
    {
        channel->subscribe(this);
    }
};

//int main()
//{
//    IChannel* channel1 = new Channel("Code with Anchit");
//    IChannel* channel2 = new Channel("Singer Sonu");
//
//    ISubscriber* sub1 = new Subscriber("Shubh");
//    ISubscriber* sub2 = new Subscriber("Ahan");
//
//    sub1->subscribeChannel(channel1);
//    sub2->subscribeChannel(channel2);
//    sub1->subscribeChannel(channel2);
//
//    channel1->uploadVideo("Learn C++ Basic");
//    channel2->uploadVideo("Tere Bin song");
//
//    delete channel1;
//    delete channel2;
//    delete sub1;
//    delete sub2;
//
//    return 0;
//}
