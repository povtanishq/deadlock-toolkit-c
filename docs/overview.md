# Overview

This project implements:
- Banker's Algorithm (avoidance)
- Resource Allocation Graph (detection)
- Deadlock recovery

## Banker's Algorithm
Uses:
- Allocation
- Max
- Need
- Available

Produces safe sequence.

## RAG
Builds graph of processes + resources.
Cycle → deadlock.

## Recovery
Selects victim → frees resources → system continues.