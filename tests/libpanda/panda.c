#include "fake_stm.h"
#include "config.h"
#include "can_definitions.h"

bool bitbang_gmlan(CANPacket_t *to_bang) { return true; }
bool can_init(uint8_t can_number) { return true; }
void process_can(uint8_t can_number) { }
//int safety_tx_hook(CANPacket_t *to_send) { return 1; }

typedef struct harness_configuration harness_configuration;
void refresh_can_tx_slots_available(void);
void can_tx_comms_resume_usb(void) { };
void can_tx_comms_resume_spi(void) { };

#include "health.h"
#include "faults.h"
#include "libc.h"
#include "boards/board_declarations.h"
#include "safety.h"
#include "main_declarations.h"
#include "drivers/can_common.h"
#include "drivers/logging.h"

// Board
const board fake_board = {
  .has_rtc_battery = true,
};
const board *current_board = &fake_board;

can_ring *rx_q = &can_rx_q;
can_ring *txgmlan_q = &can_txgmlan_q;
can_ring *tx1_q = &can_tx1_q;
can_ring *tx2_q = &can_tx2_q;
can_ring *tx3_q = &can_tx3_q;

uint32_t *logging_bank = (uint32_t *) fake_logging_bank;
uint32_t logging_bank_size = sizeof(fake_logging_bank);
uint32_t logging_rate_limit = LOGGING_MAX_LOGS_PER_MINUTE;

#include "comms_definitions.h"
#include "can_comms.h"

// libpanda stuff
#include "safety_helpers.h"
