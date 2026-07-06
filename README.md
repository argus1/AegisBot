AegisBot
===============

[![Open in MATLAB Online](https://www.mathworks.com/images/responsive/global/open-in-matlab-online.svg)](https://matlab.mathworks.com/open/github/v1?repo=argus1/ShieldBotBTFlag)

This is a route following robot used to simulate movement disorders.  The robot used is a differential-drive robot controlled with an arduino board connected to a motor and sensor shield.  The code reads IR sensor data to detect a line and adjust the course while passing flags by bluetooth to a monitor on laptop or smartphone.  

## Current Integration Decision (AGS-001)

Selected mode: **Mode C (Hybrid)** from `Dev_Plan.md`.

- Use vendor-provided low-level control where it is already stable (base manipulator control paths).
- Add custom high-level orchestration for experiment logic (line-follow, trigger, grasp sequence, resume, logging).

### Tradeoffs

- **Pros:** Faster time-to-first-demo, lower risk for hardware bring-up week, keeps room for later architecture cleanup.
- **Cons:** Mixed abstraction boundary, requires careful adapter interfaces to avoid tight coupling.

### Rejected Options

- **Mode A (vendor-only):** Rejected because experiment-specific behavior and logging would be harder to evolve cleanly.
- **Mode B (fully custom wrapper):** Rejected for Week-1 because it increases implementation risk before hardware stabilization.

![ShieldBot](https://github.com/argus1/ShieldBotBTFlag/blob/master/Prototype-of-embedded-navigation-system-guided-robot_W640.jpg?raw=true)
