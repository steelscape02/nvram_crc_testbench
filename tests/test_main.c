// tests/test_main.c
#include <stdio.h>
#include <assert.h>
#include "nvram_manager.h"
#include "mock_nvram.h"

static void test_save_and_restore_valid(void) {
    mock_nvram_init();
    const nvram_driver_t *drv = mock_nvram_get_driver();

    app_state_t saved = {.uptime_seconds = 3600, .setting_a = 42};
    app_state_t loaded = {0};

    assert(nvram_save_state(drv, 0x00, &saved) == true);
    assert(nvram_load_state(drv, 0x00, &loaded) == true);
    assert(loaded.uptime_seconds == 3600);
    assert(loaded.setting_a == 42);
    printf("PASS: test_save_and_restore_valid\n");
}

static void test_corrupted_crc_rejection(void) {
    mock_nvram_init();
    const nvram_driver_t *drv = mock_nvram_get_driver();

    app_state_t saved = {.uptime_seconds = 3600, .setting_a = 42};
    app_state_t loaded = {0};

    nvram_save_state(drv, 0x00, &saved);
    
    // Corrupt one byte of saved state in mock RAM
    mock_nvram_corrupt_byte(0x01, 0xFF);

    assert(nvram_load_state(drv, 0x00, &loaded) == false);
    printf("PASS: test_corrupted_crc_rejection\n");
}

int main(void) {
    printf("--- Running Host Unit Tests ---\n");
    test_save_and_restore_valid();
    test_corrupted_crc_rejection();
    printf("All tests passed.\n");
    return 0;
}