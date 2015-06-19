/**
 * \ file ConvolutionFilter.cpp
 */

#include <ATK/config.h>
#include <ATK/git.h>

#include <ATK/Mock/TriangleGeneratorFilter.h>
#include <ATK/Mock/TriangleCheckerFilter.h>

#include <ATK/Tools/VolumeFilter.h>
#include <ATK/Tools/SumFilter.h>

#include <ATK/EQ/CustomFIRFilter.h>
#include <ATK/EQ/IIRFilter.h>
#include <ATK/Special/ConvolutionFilter.h>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_NO_MAIN
#include <boost/test/unit_test.hpp>

#define PROCESSSIZE (1024*1024)

BOOST_AUTO_TEST_CASE( ConvolutionFilter_ramp_test )
{
  ATK::TriangleGeneratorFilter<double> generator;
  generator.set_output_sampling_rate(48000);
  generator.set_amplitude(-1);
  generator.set_frequency(1000);
  generator.process(48000/1000/4);
  
  std::vector<double> impulse;
  for(int i = 0; i < 10000; ++i)
  {
    impulse.push_back(i / 10000.);
  }
  
  ATK::IIRFilter<ATK::CustomFIRCoefficients<double> > filter;
  filter.set_input_sampling_rate(48000);
  filter.set_coefficients_in(impulse);

  ATK::ConvolutionFilter<double> convolution;
  convolution.set_input_sampling_rate(48000);
  convolution.set_impulse(impulse);

  ATK::VolumeFilter<double> gainfilter;
  gainfilter.set_input_sampling_rate(48000);
  gainfilter.set_volume(-1);

  ATK::SumFilter<double> sumfilter;
  sumfilter.set_input_sampling_rate(48000);
  
  ATK::TriangleCheckerFilter<double> checker;
  checker.set_input_sampling_rate(48000);
  checker.set_amplitude(0);
  checker.set_frequency(1000);

  filter.set_input_port(0, &generator, 0);
  convolution.set_input_port(0, &generator, 0);

  gainfilter.set_input_port(0, &filter, 0);

  sumfilter.set_input_port(0, &convolution, 0);
  sumfilter.set_input_port(1, &gainfilter, 0);
  
  checker.set_input_port(0, &sumfilter, 0);
  
  checker.process(PROCESSSIZE);
}
