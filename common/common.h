#ifndef GLOBAL_COMMON_H
#define GLOBAL_COMMON_H

#include <memory>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cstdint>

typedef unsigned char uchar;
#if defined(_WIN32) 
typedef uint64_t uint64;
#include <windows.h>
#elif defined(__unix__) || defined(__APPLE__)
typedef uint64_t uint64;
#include <unistd.h>

#endif
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <unordered_map>
#include <functional>

#include <QVector>
#include <QObject>
#include <QString>
#include <QMap>
#include <QPixmap>
#include <QSet>

using std::shared_ptr;
using std::vector;
using std::string;
using std::function;
using std::map;

#endif