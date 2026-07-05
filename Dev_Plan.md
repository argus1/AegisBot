# AegisBot Sequential Development Plan

This document converts prior strategy notes into a single execution sequence with checklist-style milestones.

## 0) Project Definition and Success Criteria

### Goals
- [ ] Define primary objective: compound dual-task robotics experiment (line-following + object grasp/hold).
- [ ] Define secondary objective: preserve educational/portfolio value (embedded + simulation + ROS integration).
- [ ] Freeze baseline metrics to compare against (single-task vs dual-task).

### Required Deliverables
- [ ] Updated firmware/control stack for mobile manipulator behavior.
- [ ] Simulation workflow (MuJoCo-first) with repeatable test scripts.
- [ ] Experiment protocol and evaluation metrics documented in repo.

---

## 1) Architecture Decision Gate (Do This First)

### Hardware/Software Platform Choice
- [ ] Fix baseline platform: **Jetson Nano + Hiwonder MasterPi** as the primary mobile-manipulator stack.
- [ ] Add hardware reference in docs: `https://www.hiwonder.com/products/masterpi`.
- [ ] Select integration mode on Jetson Nano:
	- [ ] **Mode A**: Use vendor-provided software stack directly for arm/base control.
	- [ ] **Mode B**: Wrap vendor control APIs in your own ROS node interfaces for a cleaner project architecture.
	- [ ] **Mode C**: Hybrid approach (vendor low-level control + custom high-level task/state orchestration).
- [ ] Record final integration rationale and tradeoffs in `README.md`.

### Constraints Validation
- [ ] Confirm power budget for base + arm (arm supply, drivetrain supply, grounding strategy).
- [ ] Confirm mechanical mounting feasibility (rigid adapter, center-of-gravity shift tolerance).
- [ ] Confirm camera/sensor pipeline for grasp trigger (AprilTag, color cue, or equivalent).

**Exit criteria:** Jetson Nano + MasterPi baseline is confirmed, with one integration mode selected and constraints accepted.

---

## 2) Repository Cleanup and Baseline Refactor

### Source Consolidation
- [ ] Consolidate line-follow variants (`LineFollowing1/2/2m/3/3m`) into one maintained code path.
- [ ] Preserve variant behavior behind config flags or versioned notes.

### Module Structure
- [ ] Split logic into reusable modules:
	- [ ] Sensor acquisition
	- [ ] Control policy (line-follow decision logic)
	- [ ] Actuator output
	- [ ] Communications/telemetry
- [ ] Move constants (pins, thresholds, PWM limits) into one config file.

### Reliability Fixes
- [ ] Add timeout protection to sensor read loop (replace unbounded blocking behavior).
- [ ] Ensure failsafe behavior for invalid sensor values and comms dropout.

**Exit criteria:** codebase has one canonical implementation with no unbounded sensor loop.

---

## 3) Real-Time Control Layer (RTOS / Tasked Runtime)

### Task Decomposition
- [ ] Implement fixed-rate sensor task.
- [ ] Implement motor control task consuming latest sensor state.
- [ ] Implement comms task for command/telemetry handling.
- [ ] Implement watchdog/health task.
- [ ] Implement non-blocking status indicator task.

### Concurrency Safety
- [ ] Use queue/mutex/shared-state policy consistently.
- [ ] Add task-level timing logs (sampling period, control latency).
- [ ] Validate deterministic update rates under load.

**Exit criteria:** stable multi-task runtime with deterministic control loop timing.

---

## 4) Mobile Manipulator Integration

### Mechanical Integration
- [ ] Design and install rigid arm mount.
- [ ] Re-balance chassis and verify tip margin during full arm extension.
- [ ] Re-test traction and turning with arm payload.

### Arm Control Integration
- [ ] Implement arm driver interface using MasterPi-compatible control APIs/libraries per selected integration mode.
- [ ] Define grasp primitives: pre-grasp, approach, close, lift, hold, release.
- [ ] Add safety limits (joint range, velocity caps, emergency stop).

### Perception Trigger
- [ ] Implement object/grasp trigger detection logic.
- [ ] Validate trigger precision and false-positive rate.

**Exit criteria:** base can line-follow, pause/slow for grasp, and resume with object held.

---

## 5) Compound Task State Machine

### Runtime State Design
- [ ] Implement states:
	- [ ] `LineFollow`
	- [ ] `TriggerDetected`
	- [ ] `ApproachAndGrasp`
	- [ ] `ResumeLineFollowLoaded`
	- [ ] `Dropoff` (optional)
- [ ] Define transition conditions and timeout fallbacks.
- [ ] Add recovery behavior when grasp fails.

### Metrics and Logging
- [ ] Log line-tracking error before/during/after grasp.
- [ ] Log grasp success rate and completion time.
- [ ] Log disturbances (overshoot, stop events, path deviations).

**Exit criteria:** end-to-end compound task runs repeatedly with measurable outputs.

---

## 6) Simulation-First Pipeline (MuJoCo)

### Simulation Model
- [ ] Build differential-drive + manipulator model (reuse available arm description if possible).
- [ ] Create line track definitions (straight, curved, intersections if needed).
- [ ] Implement sensor abstraction matching real controller input format.

### Software-in-the-Loop (SIL)
- [ ] Run the same control policy in simulation and hardware adapters.
- [ ] Add domain randomization (friction, noise, lighting/sensor perturbation surrogate).
- [ ] Generate repeatable benchmark scenarios.

### Validation
- [ ] Compare sim metrics vs physical tests for trend consistency.
- [ ] Tune thresholds/gains in sim, then confirm transfer to hardware.

**Exit criteria:** simulation is fast enough for iteration and predicts hardware behavior directionally.

---

## 7) Experimental Protocol and Analysis

### Protocol Definition
- [ ] Define trial sets:
	- [ ] Single-task line-follow baseline
	- [ ] Dual-task line-follow + grasp/hold
- [ ] Define number of runs per condition and acceptance criteria.
- [ ] Freeze environment variables (track layout, object type, lighting, battery state).

### Analysis Outputs
- [ ] Compute task-completion rate per condition.
- [ ] Compute trajectory error and speed variability.
- [ ] Compute grasp-induced degradation deltas.
- [ ] Summarize outcomes in plots/tables for report.

**Exit criteria:** statistically interpretable comparison between baseline and compound task.

---

## 8) Documentation and Demo Readiness

### Documentation
- [ ] Update `README.md` with architecture, setup, and run instructions.
- [ ] Document wiring/power layout and safety checklist.
- [ ] Document simulation setup and benchmark scripts.

### Demo Package
- [ ] Prepare one-command (or minimal-step) launch flow.
- [ ] Record short demo clips: baseline run, compound run, failure recovery.
- [ ] Add troubleshooting section for common failures.

**Exit criteria:** repo is understandable and reproducible by a new collaborator.

---

## 9) Final Release Checklist

- [ ] All major milestones above marked complete.
- [ ] No blocking known issues for core demo path.
- [ ] Core metrics collected and archived.
- [ ] Version/tag created for reproducible release snapshot.

---

## Immediate Next Actions (This Week)

- [ ] Finalize MasterPi integration mode (A, B, or C) on Jetson Nano.
- [ ] Consolidate legacy `.ino` files into one canonical control codebase.
- [ ] Add sensor read timeout and failsafe handling.
- [ ] Implement initial compound state machine skeleton.
- [ ] Stand up first MuJoCo scenario for line-follow baseline.

