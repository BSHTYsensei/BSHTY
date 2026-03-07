// TrustdSpoofer.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <syslog.h>
#include <Security/Security.h>

#define LOG(fmt, ...) syslog(LOG_NOTICE, "🔓 [TrustdSpoofer] " fmt, ##__VA_ARGS__)

OSStatus hooked_SecTrustEvaluate(SecTrustRef trust, SecTrustResultType *result) {
    LOG("SecTrustEvaluate 被调用");
    if (result) *result = kSecTrustResultUnspecified;
    return errSecSuccess;
}

__attribute__((constructor))
static void init() {
    LOG("TrustdSpoofer 已加载");
}
