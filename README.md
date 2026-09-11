# NVRAM CRC Testbench
> A platform-agnostic, power-loss safe state storage engine written in portable C99.

## Features
- **Integrity Verification:** CCITT CRC-16 calculation for frame validation.
- **Atomic Writes:** Dual-bank (ping-pong) buffering to prevent torn-write corruption during power brownouts.
- **Off-Target Verification:** Includes a host-side unit test harness with mock NVRAM and deterministic fault injection (simulated power loss, bit flips, partial writes).
- **Zero Dependencies:** Pure C implementation decoupled from hardware abstraction layers (HAL).
