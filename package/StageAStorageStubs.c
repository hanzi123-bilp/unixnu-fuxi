/*
 * Stage 2a definitions for the storage and power symbols the kernel references
 * but this board cannot build yet.
 *
 * Boot progress links with the audited UFS driver, the owner-root code and the
 * virtio transport selected (see build-xnu-4k-baseline.sh), so the kernel has
 * references to all three. The archives that normally answer them are research
 * instruments: build-native-virtio-bindings.py needs a live storage capture and
 * build-verified-root-probe.py needs a completed verification of the original
 * OS volume. Neither input exists in a clean checkout.
 *
 * Nothing here reports success:
 *   - fuxi has no virtio block device, so the counters stay zero and boot
 *     progress takes its UFS branch;
 *   - the owner root has no policy bundle and no trusted key on this board, so
 *     vr_open() (kits/VerifiedRoot, linked from its real sources) refuses every
 *     volume instead of accepting one;
 *   - the sheng PMGR power driver is an instrument of its own, so the poll is a
 *     no-op and the cpufreq row stays empty.
 *
 * Replace the definitions here with the real archives once their inputs exist;
 * until then they make the absence explicit instead of hiding it.
 */
#include <stddef.h>
#include <stdint.h>

/* BootProgress.c reads these as plain variables; zero means "no virtio". */
volatile uint32_t native_virtio_ready;
volatile uint32_t native_virtio_read_requests;
volatile uint32_t native_virtio_read_failures;
volatile uint64_t native_virtio_verified_blocks;

/* The policy table the owner-root mount path walks: no entries, no trusted key.
   verified_root_key is VR_KEY_BYTES of zeroes, which fails the kit's own magic
   and key checks, so vr_open() fails closed. */
const uint64_t verified_root_policy_count = 0;
const uint64_t verified_root_policies[2] = {0, 0};
const uint8_t verified_root_key[395];

/* Declared weakly by BootProgress.c, so an absent definition must still link. */
void
sheng_cpufreq_poll (
  void
  )
{
}
