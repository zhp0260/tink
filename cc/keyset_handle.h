// Copyright 2017 Google Inc.
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
//
///////////////////////////////////////////////////////////////////////////////

#ifndef TINK_KEYSET_HANDLE_H_
#define TINK_KEYSET_HANDLE_H_

#include "proto/tink.pb.h"

namespace cloud {
namespace crypto {
namespace tink {

// KeysetHandle provides abstracted access to Keysets, to limit
// the exposure of actual protocol buffers that hold sensitive
// key material.
class KeysetHandle {
 public:
  // TODO(przydatek): refactor to ensure that creation KeysetHandle-objects
  //   can be controlled (as in Java).
  KeysetHandle(const google::cloud::crypto::tink::Keyset& keyset);
  const google::cloud::crypto::tink::Keyset& get_keyset() const;

 private:
  google::cloud::crypto::tink::Keyset keyset_;
};

}  // namespace tink
}  // namespace crypto
}  // namespace cloud

#endif  // TINK_KEYSET_HANDLE_H_
