/*
 *  Copyright 2008-2009 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


/*! \file iterator_categories.inl
 *  \brief Details for iterator_categories.h.
 */

#include <thrust/iterator/iterator_categories.h>
#include <thrust/iterator/iterator_traits.h>
#include <thrust/detail/type_traits.h>

namespace thrust
{

namespace detail
{

template <typename T>
  struct is_host_iterator_category
    : thrust::detail::or_<
        thrust::detail::is_convertible<T, thrust::input_host_iterator_tag>,
        thrust::detail::is_convertible<T, thrust::output_host_iterator_tag>
      >
{
}; // end is_host_iterator_category

template <typename T>
  struct is_device_iterator_category
    : thrust::detail::or_<
        thrust::detail::is_convertible<T, thrust::input_device_iterator_tag>,
        thrust::detail::is_convertible<T, thrust::output_device_iterator_tag>
      >
{
}; // end is_device_iterator_category


template <typename T>
  struct is_iterator_category
    : thrust::detail::or_<
        is_host_iterator_category<T>,
        is_device_iterator_category<T>
      >
{
}; // end is_iterator_category


// define backend-specific iterator categories in detail for now
struct input_cuda_device_iterator_tag : input_device_iterator_tag {};
struct input_omp_device_iterator_tag : input_device_iterator_tag {};

struct output_cuda_device_iterator_tag : output_device_iterator_tag {};
struct output_omp_device_iterator_tag : output_device_iterator_tag {};

struct forward_cuda_device_iterator_tag : forward_device_iterator_tag {};
struct forward_omp_device_iterator_tag : forward_device_iterator_tag {};

struct bidirectional_cuda_device_iterator_tag : bidirectional_device_iterator_tag {};
struct bidirectional_omp_device_iterator_tag : bidirectional_device_iterator_tag {};

struct random_access_cuda_device_iterator_tag : random_access_device_iterator_tag {};
struct random_access_omp_device_iterator_tag : random_access_device_iterator_tag {};


} // end detail

} // end thrust

