/* Copyright 2018 Alibaba Group Holding Limited. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef EULER_CLIENT_LOCAL_GRAPH_H_
#define EULER_CLIENT_LOCAL_GRAPH_H_

#include <string>
#include <vector>
#include <functional>

#include "euler/client/graph.h"

#include "euler/core/graph_engine.h"

namespace euler {
namespace client {

class LocalGraph: public Graph {
  friend class Graph;
 public:
  bool Initialize(const GraphConfig& config) override;

  void SampleNode(
      int node_type,
      int count,
      std::function<void(const NodeIDVec&)> callback) const override;

  void SampleEdge(
      int edge_type,
      int count,
      std::function<void(const EdgeIDVec&)> callback) const override;

  void GetNodeType(
      const std::vector<NodeID>& node_ids,
      std::function<void(const TypeVec&)> callback) const override;

  void GetNodeFloat32Feature(
      const std::vector<NodeID>& node_ids,
      const std::vector<int>& fids,
      std::function<void(const FloatFeatureVec&)> callback) const override;

  void GetNodeUint64Feature(
      const std::vector<NodeID>& node_ids,
      const std::vector<int>& fids,
      std::function<void(const UInt64FeatureVec&)> callback) const override;

  void GetNodeBinaryFeature(
      const std::vector<NodeID>& node_ids,
      const std::vector<int>& fids,
      std::function<void(const BinaryFatureVec&)> callback) const override;

  void GetEdgeFloat32Feature(
      const std::vector<EdgeID>& edge_ids,
      const std::vector<int>& fids,
      std::function<void(const FloatFeatureVec&)> callback) const override;

  void GetEdgeUint64Feature(
      const std::vector<EdgeID>& edge_ids,
      const std::vector<int32_t>& fids,
      std::function<void(const UInt64FeatureVec&)> callback) const override;

  void GetEdgeBinaryFeature(
      const std::vector<EdgeID>& edge_ids,
      const std::vector<int>& fids,
      std::function<void(const BinaryFatureVec&)> callback) const override;

  void GetFullNeighbor(
      const std::vector<NodeID>& node_ids,
      const std::vector<int>& edge_types,
      std::function<void(const IDWeightPairVec&)> callback) const override;

  void GetSortedFullNeighbor(
      const std::vector<NodeID>& node_ids,
      const std::vector<int>& edge_types,
      std::function<void(const IDWeightPairVec&)> callback) const override;

  void GetTopKNeighbor(
      const std::vector<NodeID>& node_ids,
      const std::vector<int>& edge_types,
      int k,
      std::function<void(const IDWeightPairVec&)> callback) const override;

  void SampleNeighbor(
      const std::vector<NodeID>& node_ids,
      const std::vector<int>& edge_types,
      int count,
      std::function<void(const IDWeightPairVec&)> callback) const override;

 private:
  LocalGraph();

 private:
  euler::core::GraphEngine* engine_;
};

}  // namespace client
}  // namespace euler

#endif  // EULER_CLIENT_LOCAL_GRAPH_H_
