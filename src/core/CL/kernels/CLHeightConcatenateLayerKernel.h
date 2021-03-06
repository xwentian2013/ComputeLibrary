/*
 * Copyright (c) 2019-2020 Arm Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ARM_COMPUTE_CLHEIGHTCONCATENATELAYERKERNEL_H
#define ARM_COMPUTE_CLHEIGHTCONCATENATELAYERKERNEL_H

#include "arm_compute/core/Types.h"
#include "src/core/CL/ICLKernel.h"

namespace arm_compute
{
/** Interface for the height concatenate kernel.
 *  The input tensor will be concatenated into the output tensor.
 */
class CLHeightConcatenateLayerKernel : public ICLKernel
{
public:
    /** Default constructor */
    CLHeightConcatenateLayerKernel();
    /** Prevent instances of this class from being copied (As this class contains pointers) */
    CLHeightConcatenateLayerKernel(const CLHeightConcatenateLayerKernel &) = delete;
    /** Prevent instances of this class from being copied (As this class contains pointers) */
    CLHeightConcatenateLayerKernel &operator=(const CLHeightConcatenateLayerKernel &) = delete;
    /** Allow instances of this class to be moved */
    CLHeightConcatenateLayerKernel(CLHeightConcatenateLayerKernel &&) = default;
    /** Allow instances of this class to be moved */
    CLHeightConcatenateLayerKernel &operator=(CLHeightConcatenateLayerKernel &&) = default;
    /** Default destructor */
    ~CLHeightConcatenateLayerKernel() = default;
    /** Initialise the kernel's inputs and output
     *
     * @param[in]  compile_context The compile context to be used.
     * @param[in]  input           Input tensor. Data types supported: All.
     * @param[in]  height_offset   The starting offset on the Y axis for the output tensor.
     * @param[out] output          Output tensor. Data types supported: Same as @p input.
     *
     */
    void configure(const CLCompileContext &compile_context, ITensorInfo *input, unsigned int height_offset, ITensorInfo *output);
    /**  Static function to check if given info will lead to a valid configuration of @ref CLHeightConcatenateLayerKernel
     *
     * @param[in] input         Input tensor info. Data types supported: All.
     * @param[in] height_offset The starting offset on the Y axis for the output tensor.
     * @param[in] output        Output tensor info. Data types supported: Same as @p input.
     *
     * @return a status
     */
    static Status validate(const ITensorInfo *input, unsigned int height_offset, const ITensorInfo *output);

    // Inherited methods overridden:
    void run_op(ITensorPack &tensors, const Window &window, cl::CommandQueue &queue) override;

private:
    unsigned int _height_offset;
};
} // namespace arm_compute
#endif /* ARM_COMPUTE_CLHEIGHTCONCATENATELAYERKERNEL_H */
