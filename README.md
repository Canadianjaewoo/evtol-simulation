# evtol-simulation
Joby take-home fleet simulation 
## Overview

This project simulates the operation of a fleet of 20 eVTOL aircraft over a fixed simulation duration.

The simulation models:

- Battery energy consumption during flight
- Charging station constraints (limited chargers)
- Random fault generation during flight
- Fleet-level statistics reporting

The implementation emphasizes clarity and straightforward C++17 design without advanced abstractions.

Each `Vehicle` instance owns its own random number generator (`std::mt19937`) seeded using `std::random_device`, ensuring independent fault behavior across vehicles.

---

## Simulation Configuration

- Fleet size: 20 vehicles
- Charger count: 3 chargers
- Time step: 1 second (1/3600 hours)
- Duration: 3 hours

---

## Architecture

### Vehicle
- Implements a simple state machine:
  - Flying
  - Waiting
  - Charging
- Models battery depletion and recharge
- Generates random faults while flying

### Chargers
- Manages limited charger availability
- Ensures no more than N vehicles charge simultaneously

### Simulation
- Advances time using a fixed time-step loop
- Updates all vehicles each iteration

### StatisticsReport
- Aggregates total fleet statistics
- Computes averages and totals at end of simulation

---

## Vehicle State Machine

Flying → Waiting → Charging → Flying

Transitions occur when:

- Battery depletes
- A charger becomes available (e.g., available_)
- Charging completes

---

## Assumptions

- Single-threaded simulation
- Fixed time-step integration
- No partial time-step correction when battery depletes mid-step
- Charger allocation depends on update order (no fairness queue)
- Random number generators are independent per vehicle

---

## Build/Run

codelite 18.2.0
