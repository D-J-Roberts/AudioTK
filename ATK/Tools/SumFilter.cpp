/**
 * \file SumFilter.cpp
 */

#include "SumFilter.h"

#include <complex>
#include <cstdint>

namespace ATK
{
  template<typename DataType_>
  SumFilter<DataType_>::SumFilter()
  :Parent(2, 1)
  {
    
  }
  
  template<typename DataType_>
  SumFilter<DataType_>::~SumFilter()
  {
    
  }

  template<typename DataType_>
  void SumFilter<DataType_>::process_impl(std::size_t size) const
  {
    const DataType* ATK_RESTRICT input0 = converted_inputs[0];
    const DataType* ATK_RESTRICT input1 = converted_inputs[1];
    DataType* ATK_RESTRICT output = outputs[0];
    for(std::size_t i = 0; i < size; ++i)
    {
      output[i] = static_cast<DataType>(input0[i] + input1[i]);
    }
  }
  
  template class SumFilter<std::int16_t>;
  template class SumFilter<std::int32_t>;
  template class SumFilter<std::int64_t>;
  template class SumFilter<float>;
  template class SumFilter<double>;
  template class SumFilter<std::complex<float>>;
  template class SumFilter<std::complex<double>>;
}
