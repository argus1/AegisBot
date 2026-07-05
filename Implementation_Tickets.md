# AegisBot Implementation Tickets

Source: `Dev_Plan.md` milestones, scheduled per `Dev_Sched.md` hardware constraints.

## Usage Notes

- Status values: `TODO`, `IN-PROGRESS`, `BLOCKED`, `DONE`
- Priority values: `P0` (must-have), `P1` (important), `P2` (nice-to-have)
- Hardware gates:
  - **Jetson gate:** Mon 2026-07-06
  - **MasterPi gate:** Wed 2026-07-08

---

## Sprint 1 (Week of 2026-07-05)

## M1 — Jetson Provisioning (Mon EOD)

### AGS-001 — Finalize Integration Mode Decision
- **Status:** DONE
- **Priority:** P0
- **Depends on:** None
- **Description:** Choose Mode A/B/C from `Dev_Plan.md` and document architecture rationale.
- **Acceptance Criteria:**
  - [x] Selected mode is recorded in `README.md`
  - [x] Tradeoffs and rejected options are documented

### AGS-002 — Jetson Base OS Bring-Up
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-001
- **Description:** Flash/boot Jetson Nano and complete first-time system setup.
- **Acceptance Criteria:**
  - [ ] Jetson boots reliably
  - [ ] User/account/network configured
  - [ ] Boot reproducibility notes captured

### AGS-003 — Toolchain + Dependencies Setup
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-002
- **Description:** Install Python/C++ toolchains and required robotics/system dependencies.
- **Acceptance Criteria:**
  - [ ] Package install script or command log exists
  - [ ] Python environment resolves required imports
  - [ ] Compiler/toolchain sanity checks pass

### AGS-004 — Repo Bootstrap on Jetson
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-003
- **Description:** Clone/sync repo on Jetson and run baseline sanity scripts.
- **Acceptance Criteria:**
  - [ ] Repo checked out and clean
  - [ ] Baseline sanity script executes without fatal errors

### AGS-005 — Camera/I-O Sanity Validation
- **Status:** TODO
- **Priority:** P1
- **Depends on:** AGS-003
- **Description:** Verify camera and basic I/O paths are visible from Jetson.
- **Acceptance Criteria:**
  - [ ] Camera detection test passes
  - [ ] Basic I/O test results logged

### AGS-006 — Reproducible Setup Documentation
- **Status:** TODO
- **Priority:** P1
- **Depends on:** AGS-002, AGS-003, AGS-004
- **Description:** Document setup in `README.md` for deterministic bring-up.
- **Acceptance Criteria:**
  - [ ] Setup steps are complete and ordered
  - [ ] Fresh-machine replay checklist included

---

## M2 — Software-Only Pipeline (Tue EOD, no manipulator required)

### AGS-007 — Create Control Adapter Interface
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-001
- **Description:** Define hardware-agnostic interface for base + manipulator commands.
- **Acceptance Criteria:**
  - [ ] Interface methods cover required actions (line-follow, grasp primitives)
  - [ ] Mock implementation compiles/runs

### AGS-008 — Compound State Machine Skeleton
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-007
- **Description:** Implement `LineFollow -> TriggerDetected -> ApproachAndGrasp -> ResumeLineFollowLoaded` flow with stubs.
- **Acceptance Criteria:**
  - [ ] All states represented in code
  - [ ] Transition logic and timeout hooks implemented

### AGS-009 — Sensor Timeout + Failsafe Refactor
- **Status:** DONE
- **Priority:** P0
- **Depends on:** None
- **Description:** Replace unbounded sensor read loops with bounded timeout behavior and fallback actions.
- **Acceptance Criteria:**
  - [x] Sensor timeout path tested
  - [x] No indefinite blocking path remains

### AGS-010 — Telemetry + Logging Schema
- **Status:** TODO
- **Priority:** P1
- **Depends on:** AGS-008
- **Description:** Add CSV/JSON log schema for tracking error, grasp success, timing, and disturbances.
- **Acceptance Criteria:**
  - [ ] Log fields match experiment metrics in `Dev_Plan.md`
  - [ ] At least one dry-run log artifact generated

### AGS-011 — MuJoCo Baseline Scenario
- **Status:** TODO
- **Priority:** P1
- **Depends on:** AGS-007
- **Description:** Stand up line-follow-only simulation scenario for SIL dry-runs.
- **Acceptance Criteria:**
  - [ ] Scenario launches and runs deterministic trial
  - [ ] Trial output is captured in logs

### AGS-012 — Mocked End-to-End Dry Run
- **Status:** TODO
- **Priority:** P1
- **Depends on:** AGS-008, AGS-010
- **Description:** Execute state machine with mock manipulator responses.
- **Acceptance Criteria:**
  - [ ] State transition trace captured
  - [ ] Failure and recovery path exercised at least once

---

## M3 — MasterPi Bring-Up (Wed EOD hardware gate)

### AGS-013 — Hardware Inventory + Inspection
- **Status:** TODO
- **Priority:** P0
- **Depends on:** MasterPi arrival
- **Description:** Inventory all components and perform safety/mechanical checks.
- **Acceptance Criteria:**
  - [ ] Inventory checklist completed
  - [ ] Any missing/damaged items logged

### AGS-014 — Power and Grounding Validation
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-013
- **Description:** Verify stable power delivery under idle and motion load.
- **Acceptance Criteria:**
  - [ ] Voltage under load is within tolerance
  - [ ] Common grounding confirmed

### AGS-015 — Jetson ↔ MasterPi Control Link
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-013, AGS-014
- **Description:** Bring up control interface between Jetson and MasterPi.
- **Acceptance Criteria:**
  - [ ] Control API/transport path validated
  - [ ] Command round-trip test passes

### AGS-016 — Replace Mock with Real Backend
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-015, AGS-007
- **Description:** Swap mock manipulator backend for real hardware implementation.
- **Acceptance Criteria:**
  - [ ] State machine runs with real command backend
  - [ ] No interface contract breakages

### AGS-017 — Safe Motion Smoke Test
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-016
- **Description:** Run safe command set (home, gripper open/close, limited joint movement).
- **Acceptance Criteria:**
  - [ ] All smoke tests complete without safety incident
  - [ ] Motion limits enforced

---

## M4 — First Compound Prototype (Fri EOD)

### AGS-018 — Grasp Primitive Tuning
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-017
- **Description:** Tune pre-grasp, approach, close, lift, hold, release primitives.
- **Acceptance Criteria:**
  - [ ] ≥70% success in controlled bench attempts (initial target)
  - [ ] Repeatable timing profile logged

### AGS-019 — Trigger Perception Integration
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-005, AGS-017
- **Description:** Integrate AprilTag/color trigger detection into state machine transitions.
- **Acceptance Criteria:**
  - [ ] Trigger latency measured
  - [ ] False-positive cases documented

### AGS-020 — Recovery + Timeout Logic Hardening
- **Status:** TODO
- **Priority:** P1
- **Depends on:** AGS-018, AGS-019
- **Description:** Add robust fallback and retry policy for failed grasp/transition events.
- **Acceptance Criteria:**
  - [ ] Recovery path tested in 3+ induced failures
  - [ ] No dead-end state without operator override

### AGS-021 — Integrated Trial Batch (x10)
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-018, AGS-019, AGS-020
- **Description:** Run 10 integrated mobile-manipulator trials and capture outcomes.
- **Acceptance Criteria:**
  - [ ] 10 trial logs stored
  - [ ] Success/failure reason tagged per run

### AGS-022 — Baseline vs Dual-Task Comparison
- **Status:** TODO
- **Priority:** P0
- **Depends on:** AGS-021, AGS-010
- **Description:** Compute first-pass metrics for single-task vs compound-task behavior.
- **Acceptance Criteria:**
  - [ ] Completion rate comparison table generated
  - [ ] Tracking error and completion-time deltas computed

### AGS-023 — Demo Artifacts + Failure Notes
- **Status:** TODO
- **Priority:** P1
- **Depends on:** AGS-021
- **Description:** Record demo clips and summarize top 3 failure modes with mitigations.
- **Acceptance Criteria:**
  - [ ] Demo clips archived
  - [ ] Mitigation notes committed to repo docs

---

## Backlog Tickets (Post Week 1)

### AGS-024 — Repository Consolidation of Legacy `.ino` Variants
- **Status:** TODO
- **Priority:** P1
- **Depends on:** AGS-009
- **Description:** Merge `LineFollowing1/2/2m/3/3m` into a single maintained control path.

### AGS-025 — Simulation Domain Randomization
- **Status:** TODO
- **Priority:** P2
- **Depends on:** AGS-011
- **Description:** Add randomized friction/noise/perturbation sweeps for robustness testing.

### AGS-026 — Experimental Protocol Formalization
- **Status:** TODO
- **Priority:** P1
- **Depends on:** AGS-022
- **Description:** Finalize trial counts, acceptance criteria, and analysis scripts.

### AGS-027 — Release Readiness Checklist + Tagging
- **Status:** TODO
- **Priority:** P1
- **Depends on:** AGS-023, AGS-026
- **Description:** Verify reproducibility and create release snapshot tag.

---

## Suggested Execution Order (Critical Path)

`AGS-001 -> AGS-002 -> AGS-003 -> AGS-004 -> AGS-007 -> AGS-008 -> AGS-010 -> AGS-013 -> AGS-014 -> AGS-015 -> AGS-016 -> AGS-017 -> AGS-018 -> AGS-019 -> AGS-021 -> AGS-022`
