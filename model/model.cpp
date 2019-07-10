#include "model.h"

Model::Model() {
}
Model::~Model() {
}

shared_ptr<QVector<Channel>> Model::GetChannels() {
    return chan;
}
void Model::UpdateChannel() {}
void Model::AddChannel(QString url) {
    Channel
    chan->push_back(Channel());

}
void Model::DeleteChannel(string name) {}