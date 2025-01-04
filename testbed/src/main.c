#include <core/logger.h>
#include <core/asserts.h>

int main(void)
{
    M_FATAL("Test message for FATAL error.");
    M_ERROR("Test message for ERROR error.");
    M_WARN("Test message for WARN error.");
    M_INFO("Test message for INFO error.");
    M_DEBUG("Test message for DEBUG error.");
    M_TRACE("Test message for TRACE error.");

    M_ASSERT(1 == 0);
    
    return 0;
}