// Copyright (c) 2018 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SOURCE_REDUCE_OPERAND_TO_CONST_REDUCTION_PASS_H_
#define SOURCE_REDUCE_OPERAND_TO_CONST_REDUCTION_PASS_H_

#include "reduction_pass.h"

namespace spvtools {
namespace reduce {

// A reduction pass for turning id operands of instructions into ids of
// constants.  This reduces the extent to which ids of non-constants are used,
// paving the way for instructions that generate them to be eliminated by other
// passes.
class OperandToConstReductionPass : public ReductionPass {
 public:
  // Creates the reduction pass in the context of the given target environment
  // |target_env|
  explicit OperandToConstReductionPass(const spv_target_env target_env)
      : ReductionPass(target_env) {}

  ~OperandToConstReductionPass() override = default;

  // The name of this pass.
  std::string GetName() const final;

 protected:
  // Finds all opportunities for replacing an operand with a constant in the
  // given module.
  std::vector<std::unique_ptr<ReductionOpportunity>> GetAvailableOpportunities(
      opt::IRContext* context) const final;

 private:
};

}  // namespace reduce
}  // namespace spvtools

#endif  // SOURCE_REDUCE_OPERAND_TO_CONST_REDUCTION_PASS_H_
