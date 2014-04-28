/**
 * \file InWavFilter.h
 */

#ifndef ATK_IO_INWAVFILTER_H
#define ATK_IO_INWAVFILTER_H

#include <fstream>
#include <string>

#include <ATK/Core/TypedBaseFilter.h>

#include "config.h"
#include "WavStruct.h"

namespace ATK
{
  template<typename DataType_>
  class ATK_IO_EXPORT InWavFilter: public TypedBaseFilter<DataType_>
  {
  public:
    typedef TypedBaseFilter<DataType_> Parent;
    using typename Parent::DataType;
    using Parent::outputs_size;
    using Parent::outputs;
    using Parent::output_sampling_rate;
    using Parent::set_output_sampling_rate;
    using Parent::set_nb_output_ports;

  private:
    std::ifstream wavstream;
    WavHeader header;
    WavFormat format;
    WavData data;
    
    std::vector<std::vector<DataType> > temp_arrays;
    
    void read_from_file(std::int64_t size);

  public:
    InWavFilter(const std::string& filename);
    
    void process_impl(std::int64_t size);
  };
}
#endif
