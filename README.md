# AegisBot

[![Open in MATLAB Online](https://www.mathworks.com/images/responsive/global/open-in-matlab-online.svg)](https://matlab.mathworks.com/open/github/v1?repo=argus1/ShieldBotBTFlag)

This is a route following robot used to simulate movement disorders. The robot used is a 5 link mobile manipulator powered by a nano jetson board. The code reads IR sensor data to detect a line and adjust the course while passing flags by bluetooth to a monitor on laptop or smartphone.

## Hardware Reference

- Hiwonder MasterPi: https://www.hiwonder.com/products/masterpi

## Current Integration Decision (AGS-001)

Selected mode: **Mode B (ROS Wrapper)** from `Dev_Plan.md`.

- Wrap vendor control APIs in custom ROS node interfaces for base and arm control.
- Keep experiment logic (line-follow, trigger, grasp sequence, resume, logging) in separate high-level ROS nodes.
- Maintain a clean adapter boundary so vendor API updates can be absorbed in one integration layer.

### Tradeoffs

- **Pros:** Cleaner architecture, stronger testability and simulation portability, easier long-term maintenance.
- **Cons:** More initial integration effort than vendor-only control, requires disciplined interface design.

### Rejected Options

- **Mode A (vendor-only):** Rejected because experiment-specific behavior and logging would be harder to evolve cleanly.
- **Mode C (hybrid):** Rejected to avoid mixed abstraction boundaries and duplicated control responsibility.

![AegisBot](https://github.com/argus1/AegisBot/blob/master/Mobilemanip.gif?raw=true)
