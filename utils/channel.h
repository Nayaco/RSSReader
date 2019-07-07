#ifndef CHANNEL_H
#define CHANNEL_H

#include "common.h"

class Channel {
public:
Channel();
Channel(const Channel& chan) = delete;
Channel(const Channel&& chan);
~Channel()=default;

void DeepCopy(const Channel& chan);
std::string GetTitle();
std::string SetTitle();
std::string GetDesc();
std::string SetDesc();
std::string GetLink();
std::string SetLink();

void Update();

private:
std::string description;
std::string ttl;
std::string link;

void get(const std::string& element);
void sendRequest();


};

#endif