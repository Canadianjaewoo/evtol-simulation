# Software Requirements Specification (SRS)

## 1. Software Overview

The software shall implement a fixed time-step simulation of eVTOL aircraft using C++17.

---

## 2. Software Functional Requirements

### SRS-FR-001 – Vehicle State Machine
The software shall implement three states:
- Flying
- Waiting
- Charging

### SRS-FR-002 – Energy Consumption
While in Flying state:

BatteryEnergy -= (CruiseSpeed × EnergyPerMile × dt)

### SRS-FR-003 – Charging Control
A vehicle shall enter Charging only if `Charger::tryAcquire()` returns true.

### SRS-FR-004 – Charging Completion
A vehicle shall transition from Charging to Flying when accumulated charge time ≥ chargeTime.

### SRS-FR-005 – Fault Generation
While in Flying state:

FaultProbabilityPerStep = faultProbabilityPerHour × dt

A fault shall be recorded if:

Random(0,1) < FaultProbabilityPerStep

---

## 3. Random Number Requirements

### SRS-RNG-001
Each Vehicle shall own an independent `std::mt19937` random number generator.

### SRS-RNG-002
Each generator shall be seeded using `std::random_device` to avoid correlated random sequences.

---

## 4. Data Requirements

### SRS-DR-001
VehicleSpec parameters shall remain immutable after initialization.

### SRS-DR-002
Statistics shall be computed after simulation completes.

---

## 5. Assumptions

- Single-threaded execution
- Fixed time-step integration
- No partial time-step correction
- Charger allocation based on update order