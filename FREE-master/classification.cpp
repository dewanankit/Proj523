#include "classification.hpp"

#include <iosfwd>
#include <vector>



//#include <tbb/flow_graph.h>
#include <linux/ioctl.h>
#include <sys/time.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <fstream>
#include <iostream>
#include <atomic>

#define DEVICE_NAME "/dev/compas_fpga"
#define COMPAS_IOC_MAGIC 0xFF
#define COMPAS_IOC_LOAD_WEIGHTS _IOW(COMPAS_IOC_MAGIC, 0, int)
#define COMPAS_IOC_IMAGE        _IOW(COMPAS_IOC_MAGIC, 1, int)


typedef char* Image;
static std::atomic_int numberOfOperations;

