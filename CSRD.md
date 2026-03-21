
# Control System Requirements Document (CSRD)

## 1. System Overview

The system shall simulate the operational behavior of a fleet of eVTOL aircraft over a defined simulation duration and produce operational statistics.

---

## 2. Functional Requirements

### CSRD-FR-001 – Fleet Operation
The system shall simulate concurrent operation of 20 aircraft.

### CSRD-FR-002 – Battery Depletion
Each aircraft shall consume battery energy during flight proportional to cruise speed and energy-per-mile parameters.

### CSRD-FR-003 – Charger Limitation
The system shall limit simultaneous charging events to the number of available chargers.

### CSRD-FR-004 – Fault Modeling
The system shall simulate random faults during flight based on a defined hourly fault probability.

### CSRD-FR-005 – Statistical Reporting
The system shall report:
- Average flight time
- Average charge time
- Average distance traveled
- Total faults
- Total passenger miles

---

## 3. Performance Requirements

### CSRD-PR-001 – Time Resolution
The system shall support time advancement at 1-second resolution.

### CSRD-PR-002 – Stability Condition
The time step shall be significantly smaller than battery depletion and charging time constants.


---

## 4. System-Level to Software-Level Traceability

| CSRD ID        | SRS ID        | Description |
|----------------|--------------|-------------|
| CSRD-FR-001   | SRS-FR-001   | Fleet operation and vehicle state machine |
| CSRD-FR-002   | SRS-FR-002   | Battery depletion during flight |
| CSRD-FR-003   | SRS-FR-003   | Charger limitation logic |
| CSRD-FR-004   | SRS-FR-005   | Fault generation during flight |
| CSRD-FR-005   | SRS-DR-002   | Statistical reporting |
| CSRD-PR-001   | SRS-FR-002   | 1-second fixed time-step resolution |
| CSRD-PR-002   | SRS-FR-002   | Stability requirement for small dt |

---

## 5. Software-Level to Implementation Traceability

| SRS ID        | Implementation Location | Description |
|---------------|------------------------|-------------|
| SRS-FR-001   | Vehicle.hpp / Vehicle.cpp | Vehicle state machine logic |
| SRS-FR-002   | Vehicle::updateFlying() | Battery energy update equation |
| SRS-FR-003   | ChargerPool::tryAcquire() | Charger availability control |
| SRS-FR-004   | Vehicle::updateCharging() | Charging completion transition |
| SRS-FR-005   | Vehicle::updateFlying() | Fault probability evaluation |
| SRS-RNG-001  | Vehicle class (member rng_) | Independent RNG per vehicle |
| SRS-RNG-002  | Vehicle constructor | Seeding with std::random_device |
| SRS-DR-001   | VehicleSpec class | Immutable specification parameters |
| SRS-DR-002   | StatisticsReports.cpp | Post-simulation statistics aggregation |

---