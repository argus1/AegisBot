# Grounding and Power Plan for AegisBot

## Project-Specific Electrical Context

- Controller: Jetson Nano dev kit (945-13450-0000-100, 2 GB RAM, 4 GB storage from invoice; microSD-expandable storage).
- Mobile platform: Hiwonder MasterPi base + manipulator.
- Current portable supply candidate: Belkin BoostCharge Power Bank 20K (BPB012), connected to Jetson Nano via USB cable and taped to chassis.

## User-Provided Power Demand Inputs

- Drivetrain power: 4.8 W per motor x 4 = 19.2 W.
- Manipulator links total: 145 W.
- Jetson Nano: 10 W (module), 15-20 W with carrier board.

Estimated total peak demand from inputs:

- 179.2 W to 184.2 W (before conversion losses and startup/transient overhead).

## Feasibility Check Against BPB012

- BPB012 published output is 15 W total shared across all ports.
- Conclusion: BPB012 cannot power the full mobile manipulator stack at the stated loads.
- BPB012 may be used only for a reduced subsystem load that stays under its output limit.

## Grounding and ESD Plan (Current)

- Operating surface: butcher-paper-covered tabletop (lower static risk than carpet).
- ESD mitigation: manipulator chassis connected to dragging static discharger.
- Wiring policy: use one common electrical reference (common ground) across Jetson, motor/servo power electronics, and sensors.

## Minimum Safety/Integration Actions Before Full-Power Testing

1. Define final rail architecture (example: separate high-current rail for motors/servos and dedicated regulated rail for Jetson/computing).
2. Add appropriate fusing/current limiting on each rail.
3. Verify cable gauge and connector current rating for worst-case draw.
4. Validate brownout margin under arm motion + drive acceleration.
5. Perform a staged bring-up test:
   - Compute only
   - Compute + sensors
   - Compute + arm
   - Full system (arm + drivetrain + sensors)
6. Log peak current and rail voltage sag during each stage.

## Open Engineering Decisions

- Select final high-current power source that matches measured worst-case draw.
- Confirm whether Jetson and high-current actuators share battery source or use isolated rails with common ground.
- Confirm regulator types and target voltages per subsystem.
