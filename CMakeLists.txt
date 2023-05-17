cmake_minimum_required(VERSION 3.23)
project(Project2Graphs)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project2Graphs main.cpp
        TourismInfo/TourismNodes.cpp TourismInfo/TourismNodes.h TourismInfo/TourismGestor.cpp TourismInfo/TourismGestor.h MutablePriorityQueue.h TourismInfo/TourismVertexEdge.cpp TourismInfo/TourismVertexEdge.h TourismInfo/TourismGraph.cpp TourismInfo/TourismGraph.h
        StadiumShippingInfo/Gestor.h StadiumShippingInfo/Gestor.cpp StadiumShippingInfo/Nodes.h StadiumShippingInfo/Nodes.cpp StadiumShippingInfo/VertexEdge.h StadiumShippingInfo/VertexEdge.cpp StadiumShippingInfo/Graph.h StadiumShippingInfo/Graph.cpp
        RealWordlGraphsInfo/RealGestor.cpp RealWordlGraphsInfo/RealGestor.h RealWordlGraphsInfo/RealGraph.cpp RealWordlGraphsInfo/RealGraph.h RealWordlGraphsInfo/RealNodes.cpp RealWordlGraphsInfo/RealNodes.h RealWordlGraphsInfo/RealVertexEdge.cpp RealWordlGraphsInfo/RealVertexEdge.h
        ExtraFullyConnectedGraphsInfo/ExtraGestor.cpp ExtraFullyConnectedGraphsInfo/ExtraGestor.h ExtraFullyConnectedGraphsInfo/ExtraGraph.cpp ExtraFullyConnectedGraphsInfo/ExtraGraph.h ExtraFullyConnectedGraphsInfo/ExtraNodes.cpp ExtraFullyConnectedGraphsInfo/ExtraNodes.h ExtraFullyConnectedGraphsInfo/ExtraVertexEdge.cpp ExtraFullyConnectedGraphsInfo/ExtraVertexEdge.h)