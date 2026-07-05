# AegisBot Week-1 Execution Board

**Week:** 2026-07-05 to 2026-07-11  
**Hardware gates:** Jetson Nano (Mon), MasterPi (Wed)  
**Primary objective:** Reach first end-to-end compound prototype by Fri EOD.

---

## Board Legend

- `P0` = critical path
- `P1` = important support work
- `P2` = stretch
- `⛔ Gate` = waiting on hardware/date dependency

---

## Ready Now (Can start immediately)

- [x] **AGS-001 (P0)** Finalize integration mode decision
- [x] **AGS-009 (P0)** Sensor timeout + failsafe refactor
- [x] **SUN-01 (P0)** Define minimal demo goal for week
- [x] **SUN-02 (P1)** Create logging template (CSV/JSON fields)
- [x] **SUN-03 (P1)** Prepare repo folders: `jetson/`, `control/`, `sim/`, `logs/`

---

## Monday — Jetson Bring-Up Lane (M1)

- [ ] **AGS-002 (P0)** Jetson base OS bring-up
- [ ] **AGS-003 (P0)** Toolchain + dependencies setup
- [ ] **AGS-004 (P0)** Repo bootstrap on Jetson
- [ ] **AGS-005 (P1)** Camera/I-O sanity validation
- [ ] **AGS-006 (P1)** Reproducible setup documentation

**M1 Exit Check (Mon EOD):**
- [ ] Jetson provisioned and stable
- [ ] Setup steps documented and reproducible

---

## Tuesday — Software-Only Lane (M2, no manipulator)

- [ ] **AGS-007 (P0)** Create control adapter interface
- [ ] **AGS-008 (P0)** Compound state machine skeleton
- [ ] **AGS-010 (P1)** Telemetry + logging schema
- [ ] **AGS-011 (P1)** MuJoCo baseline scenario
- [ ] **AGS-012 (P1)** Mocked end-to-end dry run

**M2 Exit Check (Tue EOD):**
- [ ] Mock-backed pipeline runs
- [ ] State transitions + logs verified

---

## Wednesday — Hardware Arrival Lane (M3)

- [ ] **AGS-013 (P0)** Hardware inventory + inspection
- [ ] **AGS-014 (P0)** Power and grounding validation
- [ ] **AGS-015 (P0)** Jetson ↔ MasterPi control link
- [ ] **AGS-016 (P0)** Replace mock with real backend
- [ ] **AGS-017 (P0)** Safe motion smoke test

**M3 Exit Check (Wed EOD):**
- [ ] MasterPi responds safely to Jetson commands

---

## Thursday/Friday — Integration + Demo Lane (M4)

- [ ] **AGS-018 (P0)** Grasp primitive tuning
- [ ] **AGS-019 (P0)** Trigger perception integration
- [ ] **AGS-020 (P1)** Recovery + timeout hardening
- [ ] **AGS-021 (P0)** Integrated trial batch (x10)
- [ ] **AGS-022 (P0)** Baseline vs dual-task comparison
- [ ] **AGS-023 (P1)** Demo artifacts + failure notes

**M4 Exit Check (Fri EOD):**
- [ ] End-to-end compound task demonstrated
- [ ] First-pass comparative metrics captured

---

## Blocked / Waiting (Gate-Dependent)

- [ ] **AGS-013..AGS-017** ⛔ Gate: MasterPi arrival on Wed
- [ ] **AGS-018..AGS-023** ⛔ Gate: complete AGS-017 first

---

## Done This Week

- [x] Freeze baseline architecture (Jetson Nano + MasterPi)
- [x] Convert `Dev_Plan.md` milestones into implementation tickets/tasks
- [x] SUN-01 Define minimal demo goal for week
- [x] SUN-02 Create logging template (CSV/JSON fields)
- [x] SUN-03 Prepare repo folders (`jetson/`, `control/`, `sim/`, `logs/`)
- [x] AGS-001 Finalize integration mode decision
- [x] AGS-009 Sensor timeout + failsafe refactor

---

## Daily Stand-up Template (copy/paste)

### Today
- [ ]

### In Progress
- [ ]

### Blocked
- [ ]

### Done
- [ ]

### Next
- [ ]
