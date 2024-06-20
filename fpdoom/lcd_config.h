#if CHIP == 1
static const uint8_t cmd8585_init[] = {
	LCM_DELAY(120),
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	//LCM_CMD(0x36, 1), 0x00, // Memory Access Control
	LCM_CMD(0xb2, 5), 0x0c,0x0c,0x00,0x33,0x33, // Porch Setting
	LCM_CMD(0xb7, 1), 0x35, // Gate Control
	LCM_CMD(0xbb, 1), 0x2b, // VCOM Setting
	LCM_CMD(0xc0, 1), 0x2c, // LCM Control
	LCM_CMD(0xc2, 1), 0x01,
	LCM_CMD(0xc3, 1), 0x17,
	LCM_CMD(0xc4, 1), 0x20,
	LCM_CMD(0xc6, 1), 0x0b,
	LCM_CMD(0xca, 1), 0x0f,
	LCM_CMD(0xc8, 1), 0x08,
	// Write Content Adaptive Brightness Control and Color Enhancement
	LCM_CMD(0x55, 1), 0x90,
	LCM_CMD(0xd0, 2), 0xa4,0xa1, // Power Control 1
	LCM_CMD(0x3a, 1), 0x55, // Interface Pixel Format
	// Positive Voltage Gamma Control
	LCM_CMD(0xe0, 14), 0xf0,0x00,0x0a,0x10,
		0x12,0x1b,0x39,0x44, 0x47,0x28,0x12,0x10, 0x16,0x1b,
	// Negative Voltage Gamma Control
	LCM_CMD(0xe1, 14), 0xf0,0x00,0x0a,0x10,
		0x11,0x1a,0x3b,0x34, 0x4e,0x3a,0x17,0x16, 0x21,0x22,
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

#if 0
static const uint8_t cmd8585_off[] = {
	LCM_CMD(0x28, 0), // Display OFF
	LCM_DELAY(50),
	LCM_CMD(0x10, 0), // Enter Sleep Mode
	LCM_DELAY(50),
	LCM_END
};
#endif

static const uint8_t cmd9305_init[] = {
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	//LCM_CMD(0x36, 1), 0x48, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0x35, 1), 0x00,
	LCM_CMD(0x44, 2), 0x00,0x30,
	LCM_CMD(0xa4, 2), 0x44,0x44, // Vcore voltage Control
	LCM_CMD(0xa5, 2), 0x42,0x42,
	LCM_CMD(0xaa, 2), 0x88,0x88,
	LCM_CMD(0xe8, 2), 0x12,0x0b, // Frame Rate
	LCM_CMD(0xe3, 2), 0x01,0x10,
	LCM_CMD(0xff, 1), 0x61,
	LCM_CMD(0xac, 1), 0x00,
	LCM_CMD(0xae, 1), 0x2b,
	LCM_CMD(0xad, 1), 0x33,
	LCM_CMD(0xaf, 1), 0x55,
	LCM_CMD(0xa6, 2), 0x2a,0x2a, // Vreg1a voltage Control
	LCM_CMD(0xa7, 2), 0x2b,0x2b, // Vreg1b voltage Control
	LCM_CMD(0xa8, 2), 0x18,0x18, // Vreg2a voltage Control
	LCM_CMD(0xa9, 2), 0x2a,0x2a, // Vreg2b voltage Control
	LCM_CMD(0xf0, 6), 0x02,0x02,0x00,0x08,0x0c,0x10, // Set Gamma 1
	LCM_CMD(0xf1, 6), 0x01,0x00,0x00,0x14,0x1d,0x0e, // Set Gamma 2
	LCM_CMD(0xf2, 6), 0x10,0x09,0x37,0x04,0x04,0x48, // Set Gamma 3
	LCM_CMD(0xf3, 6), 0x10,0x0b,0x3f,0x05,0x05,0x4e, // Set Gamma 4
	LCM_CMD(0xf4, 6), 0x0d,0x19,0x19,0x1d,0x1e,0x0f, // Set Gamma 5
	LCM_CMD(0xf5, 6), 0x06,0x12,0x13,0x1a,0x1b,0x0f, // Set Gamma 6
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd9306_init[] = {
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	//LCM_CMD(0x36, 1), 0x48, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0xad, 1), 0x33, // ???
	LCM_CMD(0xaf, 1), 0x55, // ???
	LCM_CMD(0xae, 1), 0x2b, // ???
	LCM_CMD(0xa4, 2), 0x44,0x44, // Vcore voltage Control
	LCM_CMD(0xa5, 2), 0x42,0x42, // ???
	LCM_CMD(0xaa, 2), 0x88,0x88, // ???
	LCM_CMD(0xae, 1), 0x2b, // ???
	LCM_CMD(0xe8, 2), 0x11,0x0b, // Frame Rate
	LCM_CMD(0xe3, 2), 0x01,0x10, // ???
	LCM_CMD(0xff, 1), 0x61, // ???
	LCM_CMD(0xac, 1), 0x00, // ???
	LCM_CMD(0xaf, 1), 0x67, // ???
	LCM_CMD(0xa6, 2), 0x2a,0x2a, // Vreg1a voltage Control
	LCM_CMD(0xa7, 2), 0x2b,0x2b, // Vreg1b voltage Control
	LCM_CMD(0xa8, 2), 0x18,0x18, // Vreg2a voltage Control
	LCM_CMD(0xa9, 2), 0x2a,0x2a, // Vreg2b voltage Control
	LCM_CMD(0xf0, 6), 0x02,0x00,0x00,0x1b,0x1f,0x0b, // Set Gamma 1
	LCM_CMD(0xf1, 6), 0x01,0x03,0x00,0x28,0x2b,0x0e, // Set Gamma 2
	LCM_CMD(0xf2, 6), 0x0b,0x08,0x3b,0x04,0x03,0x4c, // Set Gamma 3
	LCM_CMD(0xf3, 6), 0x0e,0x07,0x46,0x04,0x05,0x51, // Set Gamma 4
	LCM_CMD(0xf4, 6), 0x08,0x15,0x15,0x1f,0x22,0x0f, // Set Gamma 5
	LCM_CMD(0xf5, 6), 0x0b,0x13,0x11,0x1f,0x21,0x0f, // Set Gamma 6
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd9300_init[] = {
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	//LCM_CMD(0x36, 1), 0x48, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0xa4, 2), 0x44,0x44, // Vcore voltage Control
	LCM_CMD(0xa5, 2), 0x42,0x42,
	LCM_CMD(0xaa, 2), 0x88,0x88,
	LCM_CMD(0xe8, 2), 0x12,0x0b, // Frame Rate
	LCM_CMD(0xe3, 2), 0x01,0x10,
	LCM_CMD(0xff, 1), 0x61,
	LCM_CMD(0xac, 1), 0x00,
	LCM_CMD(0xad, 1), 0x33,
	LCM_CMD(0xae, 1), 0x2b,
	LCM_CMD(0xaf, 1), 0x55,
	LCM_CMD(0xa6, 2), 0x2a,0x2a, // Vreg1a voltage Control
	LCM_CMD(0xa7, 2), 0x2b,0x2b, // Vreg1b voltage Control
	LCM_CMD(0xa8, 2), 0x10,0x10, // Vreg2a voltage Control
	LCM_CMD(0xa9, 2), 0x2a,0x2a, // Vreg2b voltage Control
	LCM_CMD(0x35, 1), 0x00,
	LCM_CMD(0x44, 2), 0x00,0x0a,
	LCM_CMD(0xf0, 6), 0x02,0x00,0x00,0x0a,0x0e,0x10, // Set Gamma 1
	LCM_CMD(0xf1, 6), 0x01,0x02,0x00,0x28,0x35,0x0f, // Set Gamma 2
	LCM_CMD(0xf2, 6), 0x10,0x09,0x35,0x03,0x03,0x43, // Set Gamma 3
	LCM_CMD(0xf3, 6), 0x11,0x0b,0x54,0x05,0x03,0x60, // Set Gamma 4
	LCM_CMD(0xf4, 6), 0x0c,0x17,0x16,0x11,0x12,0x0f, // Set Gamma 5
	LCM_CMD(0xf5, 6), 0x08,0x17,0x17,0x2a,0x2a,0x0f, // Set Gamma 6
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

#if 0
static const uint8_t cmd93xx_off[] = {
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	LCM_CMD(0x28, 0), // Display OFF
	LCM_DELAY(120),
	LCM_CMD(0x10, 0), // Enter Sleep Mode
	LCM_DELAY(120),
	LCM_END
};
#endif

static const uint8_t cmd9102_init[] = {
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	//LCM_CMD(0x36, 1), 0xd0, // Memory Access Control
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	LCM_CMD(0xa8, 1), 0x02, // ???
	LCM_CMD(0xa7, 1), 0x02, // ???
	LCM_CMD(0xea, 1), 0x3a, // ???
	LCM_CMD(0xb4, 1), 0x00, // Display Inversion Control
	LCM_CMD(0xff, 1), 0x0b, // Power Control 4
	LCM_CMD(0xfd, 1), 0x04, // Power Control 3
	LCM_CMD(0xe3, 1), 0x07, // ???
	LCM_CMD(0xa4, 1), 0x08,	// Power Control 1
	LCM_CMD(0xa3, 3), 0x07,0x16,0x16, // Frame Rate
	LCM_CMD(0xe7, 2), 0x94,0x88, // ???
	LCM_CMD(0xed, 1), 0x11, // Power Control 2
	LCM_CMD(0xe4, 1), 0xc5, // ???
	LCM_CMD(0xe2, 1), 0x80, // ???
	LCM_CMD(0xe5, 1), 0x10, // ???

	LCM_CMD(0xf0, 1), 0x55,	// Set Gamma 1
	LCM_CMD(0xf1, 1), 0x37,	// Set Gamma 2
	LCM_CMD(0xf2, 1), 0x01,	// Set Gamma 3
	LCM_CMD(0xf3, 1), 0x52,	// Set Gamma 4
	LCM_CMD(0xf4, 1), 0x00,	// Set Gamma 5
	LCM_CMD(0xf5, 1), 0x00,	// Set Gamma 6
	// 0xf6 skipped
	LCM_CMD(0xf7, 1), 0x67,	// Set Gamma 7
	LCM_CMD(0xf8, 1), 0x22, // Set Gamma 8
	LCM_CMD(0xf9, 1), 0x54,	// Set Gamma 9
	LCM_CMD(0xfa, 1), 0x05,	// Set Gamma 10
	LCM_CMD(0xfb, 1), 0x00,	// Set Gamma 11
	LCM_CMD(0xfc, 1), 0x00,	// Set Gamma 12

	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(200),
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd9106_init[] = {
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	LCM_CMD(0xb3, 1), 0x03, // ???
	LCM_CMD(0xb6, 1), 0x01, // ???
	LCM_CMD(0xa3, 1), 0x11, // Frame Rate
	LCM_CMD(0x21, 0), // Display Inversion ON
	//LCM_CMD(0x36, 1), 0x00, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0xb4, 1), 0x21, // Display Inversion Control
	// Set Gamma 1
	LCM_CMD(0xf0, 14), 0x31,0x4c,0x24,0x58,
		0xa8,0x26,0x28,0x00, 0x2c,0x0c,0x0c,0x15, 0x15,0x0f,
	// Set Gamma 2
	LCM_CMD(0xf1, 14), 0x0e,0x2d,0x24,0x3e,
		0x99,0x12,0x13,0x00, 0x0a,0x0d,0x0d,0x14, 0x13,0x0f,
	//LCM_CMD(0xfe, 0), // Inter Register Enable 1
	//LCM_CMD(0xff, 0), // ???
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x29, 0), // Display ON
	//LCM_DELAY(120),
	LCM_END
};

static const uint8_t cmd1C80F3_init[] = {
	//LCM_DELAY(120),
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	//LCM_CMD(0x36, 1), 0xd8, // Memory Access Control
	LCM_CMD(0x35, 1), 0x00, // Tearing Effect Line ON
	LCM_CMD(0x26, 1), 0x01, // Gamma Set
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd1529_init[] = {
	//LCM_DELAY(100),
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(200),
	// Manufacturer Command Access Protect
	LCM_CMD(0xb0, 1), 0x04,
	LCM_CMD(0xb3, 5), 0x02,0x00,0x00,0x00,0x00,
	// Display mode and Frame memory write mode
	LCM_CMD(0xb4, 1), 0x00,
	// Panel Driving Setting
	LCM_CMD(0xc0, 8), 0x03,0xdf,0x40,0x10,0x00,0x01,0x00,0x55,
	// Display Timing Setting for Normal Mode
	LCM_CMD(0xc1, 5), 0x07,0x27,0x08,0x08,0x00,
	// Source/Gate Driving Timing Setting
	LCM_CMD(0xc4, 4), 0x57,0x00,0x05,0x03,
	// DPI polarity Control
	LCM_CMD(0xc6, 1), 0x04,
#define GAMMA 0x03,0x12,0x1a,0x24, 0x32,0x4b,0x3b,0x29, 0x1f,0x18,0x12,0x04
	// Gamma Setting A set
	LCM_CMD(0xc8, 24), GAMMA, GAMMA,
	// Gamma Setting B set
	LCM_CMD(0xc9, 24), GAMMA, GAMMA,
	// Gamma Setting C set
	LCM_CMD(0xca, 24), GAMMA, GAMMA,
#undef GAMMA
	LCM_CMD(0xd0, 16),	// Power Setting
		0x99,0x06,0x08,0x20, 0x29,0x04,0x01,0x00,
		0x08,0x01,0x00,0x06, 0x01,0x00,0x00,0x20,
	// VCOM Setting
	LCM_CMD(0xd1, 4), 0x00,0x28,0x28,0x15,
	// NVM Access Control
	//LCM_CMD(0xe0, 3), 0x00,0x00,0x00,
	//LCM_CMD(0xe1, 6), 0x00,0x00,0x00,0x00,0x00,0x00,
	// NVM Load Control
	//LCM_CMD(0xe2, 1), 0x00,
	//LCM_CMD(0x36, 1), 0x00, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x55, // Pixel Format Set
	//LCM_CMD(0x2a, 4), 0x00,0x00,0x01,0x3f,
	//LCM_CMD(0x2b, 4), 0x00,0x00,0x01,0xdf,
	LCM_CMD(0x29, 0), // Display ON
	LCM_DELAY(120),
	//LCM_CMD(0x2c, 0),
	LCM_END
};

static const uint8_t cmd3033_init[] = {
	LCM_CMD(0x01, 0), // Software Reset
	LCM_DELAY(300),
	LCM_CMD(0xfd, 2), 0x06,0x07, // Extended command
	LCM_CMD(0x66, 1), 0x80, // Power control 3
	LCM_CMD(0x80, 1), 0x05,
	LCM_DELAY(5),
	LCM_CMD(0x80, 1), 0x01,
	LCM_DELAY(100),
	LCM_CMD(0xb6, 2), 0x02,0xa2, // Display function control
	LCM_CMD(0x60, 1), 0x26, // Power control 0
	LCM_CMD(0x63, 1), 0x08,
	LCM_CMD(0x64, 1), 0x0c, // Power control 1
	LCM_CMD(0x68, 1), 0x70,
	LCM_CMD(0x69, 1), 0x1a, // Power control 4
	LCM_CMD(0x6a, 1), 0xc4, // Power control 5
	LCM_CMD(0x6b, 1), 0x1e, // Vcom control 1
	LCM_CMD(0x6c, 1), 0x1a, // Vcom control 2
	LCM_CMD(0x6d, 1), 0x77,
	LCM_CMD(0x6e, 1), 0x84, // Power control 6
	LCM_CMD(0x6f, 1), 0x48,
	LCM_CMD(0xf7, 1), 0x10, // lcd ac drive control
	LCM_CMD(0x70, 1), 0x44,
	LCM_CMD(0x71, 1), 0x05, // Power control 7
	// Source, VCOM driver timing
	LCM_CMD(0xed, 6), 0xf9,0xf9,0x00,0x00,0x11,0x00,

	// Gamma control 1-6
	LCM_CMD(0xe0, 7), 0x0d,0x17,0x0d,0x1f,0x03,0x0d,0x17,
	LCM_CMD(0xe1, 2), 0x28,0x58,
	LCM_CMD(0xe2, 6), 0x1b,0x25,0x24,0x11,0x0a,0x17,
	LCM_CMD(0xe3, 7), 0x07,0x13,0x01,0x13,0x08,0x13,0x07,
	LCM_CMD(0xe4, 2), 0x08,0x4c,
	LCM_CMD(0xe5, 6), 0x17,0x24,0x1c,0x19,0x1a,0x1f,

	LCM_CMD(0x66, 1), 0x9c, // Power control 3
	LCM_CMD(0x67, 1), 0x07,
	LCM_CMD(0xb1, 2), 0x00,0x12, // Frame rate control 1
	// Gate driver timing
	LCM_CMD(0xec, 6), 0x33,0x16,0x16,0x00,0x18,0x18,
	LCM_CMD(0xf6, 3), 0x01,0x10,0x00, // Interface control
	LCM_CMD(0xfd, 2), 0xfa,0xfb, // Extended command
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(300),
	LCM_CMD(0x35, 1), 0x00, // Tearing Effect Line ON
	LCM_CMD(0x44, 2), 0x00,0x3f, // Set Tear Scanline
	//LCM_CMD(0x36, 1), 0x08, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x65, // Pixel Format Set
	LCM_CMD(0x29, 0), // Display ON
	LCM_DELAY(10),
	LCM_END
};

static const uint8_t cmd80F6_init[] = {
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	LCM_CMD(0x13, 0), // Normal Display Mode ON
	LCM_CMD(0x38, 0), // Idle Mode OFF
	LCM_CMD(0x20, 0), // Display Inversion OFF
	//LCM_CMD(0x36, 1), 0x00, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0x35, 1), 0x00, // Tearing Effect Line ON
	LCM_CMD(0x44, 2), 0x00,0x10, // Set Tear Scanline
	LCM_CMD(0x89, 1), 0x0b,
	LCM_CMD(0xeb, 1), 0x02,
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd8552_init[] = {
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	//LCM_CMD(0x36, 1), 0x00, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x55, // Pixel Format Set
	LCM_CMD(0xb2, 5), 0x0c,0x0c,0x00,0x33,0x33, // Porch Setting
	LCM_CMD(0xb7, 1), 0x35, // Gate Control
	LCM_CMD(0xbb, 1), 0x35, // VCOM Setting
	LCM_CMD(0xc0, 1), 0x2c, // LCM Control
	LCM_CMD(0xc2, 1), 0x01, // VDV and VRH Command Enable
	LCM_CMD(0xc3, 1), 0x0b, // VRH Set
	LCM_CMD(0xc4, 1), 0x20, // VDV Set
	LCM_CMD(0xc6, 1), 0x0b, // Frame Rate Control in Normal Mode
	LCM_CMD(0xd0, 2), 0xa4,0xa1, // Power Control 1
	// Set Gamma 1
	LCM_CMD(0xe0, 14), 0xd0,0x00,0x02,0x07,
		0x0b,0x1a,0x31,0x54, 0x40,0x29,0x12,0x12, 0x12,0x17,
	// Set Gamma 2
	LCM_CMD(0xe1, 14), 0xd0,0x00,0x02,0x07,
		0x05,0x25,0x2d,0x44, 0x45,0x1c,0x18,0x16, 0x1c,0x1d,
	LCM_CMD(0x44, 2), 0x00,0x08, // Set Tear Scanline
	LCM_CMD(0x35, 1), 0x01, // Tearing Effect Line ON
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd9304_init[] = {
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	//LCM_CMD(0x36, 1), 0x48, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x55, // Pixel Format Set
	LCM_CMD(0xe8, 2), 0x1f,0x40, // Frame Rate
	LCM_CMD(0x35, 1), 0x01, // Tearing Effect Line ON
	LCM_CMD(0x44, 2), 0x00,0x08, // Set Tear Scanline
	LCM_CMD(0xe3, 2), 0x01,0x04,
	LCM_CMD(0xa5, 2), 0x40,0x40,
	LCM_CMD(0xa4, 2), 0x44,0x44, // Vcore voltage Control
	LCM_CMD(0xab, 1), 0x08,
	LCM_CMD(0xaa, 2), 0x88,0x88,
	LCM_CMD(0xae, 1), 0x0b,
	LCM_CMD(0xac, 1), 0x00,
	LCM_CMD(0xaf, 1), 0x77,
	LCM_CMD(0xad, 1), 0x77,
	LCM_CMD(0xf0, 6), 0x02,0x00,0x00,0x00,0x03,0x08, // Set Gamma 1
	LCM_CMD(0xf1, 6), 0x01,0x03,0x00,0x00,0x05,0x0c, // Set Gamma 2
	LCM_CMD(0xf2, 6), 0x0a,0x07,0x32,0x05,0x05,0x46, // Set Gamma 3
	LCM_CMD(0xf3, 6), 0x0d,0x09,0x3a,0x04,0x04,0x4b, // Set Gamma 4
	LCM_CMD(0xf4, 6), 0x0e,0x17,0x15,0x1b,0x1e,0x00, // Set Gamma 5
	LCM_CMD(0xf5, 6), 0x0c,0x1a,0x1c,0x17,0x1a,0x00, // Set Gamma 6
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd90FA_init[] = {
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x13, 0), // Normal Display Mode ON
	LCM_CMD(0x38, 0), // Idle Mode OFF
	LCM_CMD(0x20, 0), // Display Inversion OFF
	//LCM_CMD(0x36, 1), 0x00, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0x35, 1), 0x00, // Tearing Effect Line ON
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd9290F6_init[] = {
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	//LCM_CMD(0x36, 1), 0x00, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0x35, 1), 0x00, // Tearing Effect Line ON
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd83760F_init[] = {
	//LCM_DELAY(120),
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0xb1, 3), 0x05,0x3c,0x3c,
	LCM_CMD(0xb2, 3), 0x05,0x3c,0x3c,
	LCM_CMD(0xb3, 6), 0x05,0x3c,0x3c,0x05,0x3c,0x3c,
	LCM_CMD(0xb4, 2), 0x03,0x02,
	LCM_CMD(0xc0, 3), 0xa4,0x04,0x84,
	LCM_CMD(0xc1, 1), 0xc4,
	LCM_CMD(0xc2, 2), 0x0d,0x00,
	LCM_CMD(0xc3, 2), 0x8d,0x2a,
	LCM_CMD(0xc4, 2), 0x8d,0xee,
	LCM_CMD(0xc5, 1), 0x04,
	// Set Gamma 1
	LCM_CMD(0xe0, 16), 0x05,0x19,0x14,0x17,0x3d,0x38,0x2e,0x2f,
		0x2d,0x29,0x31,0x3b,0x00,0x03,0x00,0x10,
	// Set Gamma 2
	LCM_CMD(0xe1, 16), 0x04,0x15,0x0e,0x10,0x31,0x2d,0x29,0x2d,
		0x2b,0x28,0x2e,0x39,0x00,0x01,0x02,0x10,
	LCM_CMD(0x35, 1), 0x00, // Tearing Effect Line ON
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	//LCM_CMD(0x36, 1), 0xd0, // Memory Access Control
	LCM_CMD(0x21, 0),
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};
#endif

#if CHIP == 2 || CHIP == 3
static const uint8_t cmd9106_init[] = {
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	LCM_CMD(0xb3, 1), 0x03, // ???
	LCM_CMD(0xb6, 1), 0x01, // ???
	LCM_CMD(0xa3, 1), 0x11, // Frame Rate
	LCM_CMD(0x21, 0), // Display Inversion ON
	//LCM_CMD(0x36, 1), 0xd0, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0xb4, 1), 0x21, // Display Inversion Control
	// Set Gamma 1
	LCM_CMD(0xf0, 14), 0x0c,0x46,0x25,0x56,
		0xac,0x24,0x25,0x00, 0x00,0x12,0x15,0x16, 0x17,0x0f,
	// Set Gamma 2
	LCM_CMD(0xf1, 14), 0x00,0x26,0x25,0x3a,
		0xb9,0x0f,0x10,0x00, 0x00,0x07,0x07,0x17, 0x16,0x0f,
	//LCM_CMD(0xfe, 0), // Inter Register Enable 1
	//LCM_CMD(0xff, 0), // ???
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x29, 0), // Display ON
	//LCM_DELAY(120),
	LCM_END
};

static const uint8_t cmd9108_init[] = {
	LCM_DELAY(120),
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	LCM_CMD(0xb3, 1), 0x03,
	LCM_CMD(0xb6, 1), 0x01,
	LCM_CMD(0xa3, 1), 0x11,
	LCM_CMD(0x21, 0),
	//LCM_CMD(0x36, 1), 0xd0, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0xb4, 1), 0x21,
	// Set Gamma 1
	LCM_CMD(0xf0, 14), 0x25,0x58,0x24,0x68,
		0xad,0x36,0x38,0x00, 0x0b,0x15,0x15,0x17, 0x15,0x0f,
	// Set Gamma 2
	LCM_CMD(0xf1, 14), 0x00,0x1e,0x25,0x30,
		0x97,0x03,0x03,0x00, 0x00,0x07,0x07,0x15, 0x14,0x0f,
	LCM_CMD(0x35, 1), 0x00,
	LCM_CMD(0x44, 1), 0x00,
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

// 240x240
static const uint8_t cmd9307_init240[] = {
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	//LCM_CMD(0x36, 1), 0x48, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0x86, 1), 0x98,
	LCM_CMD(0x89, 1), 0x03,
	LCM_CMD(0x8b, 1), 0x80,
	LCM_CMD(0x8d, 1), 0x22,
	LCM_CMD(0xe8, 2), 0x13,0x00,
	LCM_CMD(0xc3, 1), 0x27,
	LCM_CMD(0xc4, 1), 0x18,
	LCM_CMD(0xc9, 1), 0x1f,
	LCM_CMD(0xc5, 1), 0x0f,
	LCM_CMD(0xc6, 1), 0x10,
	LCM_CMD(0xc7, 1), 0x10,
	LCM_CMD(0xc8, 1), 0x10,
	LCM_CMD(0xff, 1), 0x62,
	LCM_CMD(0x99, 1), 0x3e,
	LCM_CMD(0x9d, 1), 0x4b,
	LCM_CMD(0x8e, 1), 0x0f,
	LCM_CMD(0xf0, 6), 0x8f,0x16,0x06,0x06,0x06,0x3c,
	LCM_CMD(0xf2, 6), 0x8f,0x13,0x06,0x06,0x07,0x3b,
	LCM_CMD(0xf1, 6), 0x52,0xbc,0x8f,0x35,0x38,0x4f,
	LCM_CMD(0xf3, 6), 0x54,0xbc,0x8f,0x33,0x3c,0x4f,
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd9307_init[] = {
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	//LCM_CMD(0x36, 1), 0x48, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0x35, 1), 0x00,
	LCM_CMD(0x44, 2), 0x00,0x10,
	LCM_CMD(0x21, 0),
	LCM_CMD(0x86, 1), 0x99,
	LCM_CMD(0x87, 1), 0x79,
	LCM_CMD(0x89, 1), 0x03,
	LCM_CMD(0xe8, 2), 0x22,0x70,
	LCM_CMD(0x8b, 1), 0x80,
	LCM_CMD(0x8d, 1), 0x22,
	LCM_CMD(0x8e, 1), 0x0f,
	LCM_CMD(0xc3, 1), 0x2a,
	LCM_CMD(0xc4, 1), 0x05,
	LCM_CMD(0xc9, 1), 0x0a,
	LCM_CMD(0xff, 1), 0x62,
	LCM_CMD(0x99, 1), 0x3e,
	LCM_CMD(0x9d, 1), 0x4b,
	LCM_CMD(0x8a, 1), 0x40,
	LCM_CMD(0xf6, 1), 0x00,
	LCM_CMD(0xf0, 6), 0x81,0x00,0x13,0x14,0x0b,0x45,
	LCM_CMD(0xf1, 6), 0x58,0x77,0x76,0x2b,0x34,0x6f,
	LCM_CMD(0xf2, 6), 0x44,0x00,0x19,0x17,0x0d,0x46,
	LCM_CMD(0xf3, 6), 0x55,0xb7,0xd5,0x28,0x24,0xff,
	//LCM_CMD(0xfe, 0), // Inter Register Enable 1
	//LCM_CMD(0xee, 0), // ???
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd7C89F0_init[] = {
	//LCM_DELAY(120),
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	// Frame Rate Control 1-3
	LCM_CMD(0xb1, 3), 0x01,0x08,0x05,
	LCM_CMD(0xb2, 3), 0x01,0x08,0x05,
	LCM_CMD(0xb3, 6), 0x01,0x08,0x05,0x05,0x08,0x05,
	LCM_CMD(0xb4, 1), 0x03,	// Display Inversion Control
	// Power Control 1-5
	LCM_CMD(0xc0, 3), 0x28,0x08,0x04,
	LCM_CMD(0xc1, 1), 0xc0,
	LCM_CMD(0xc2, 2), 0x0d,0x00,
	LCM_CMD(0xc3, 2), 0x8d,0x2a,
	LCM_CMD(0xc4, 2), 0x8d,0xee,
	LCM_CMD(0xc5, 1), 0x14, // VCOM Control 1
	//LCM_CMD(0x36, 1), 0xc8, // Memory Access Control
	// Set Gamma 1
	LCM_CMD(0xe0, 16), 0x07,0x18,0x0c,0x15,
		0x2e,0x2a,0x23,0x28, 0x28,0x28,0x2e,0x39, 0x00,0x03,0x02,0x10,
	// Set Gamma 2
	LCM_CMD(0xe1, 16), 0x06,0x23,0x0d,0x17,
		0x35,0x30,0x2a,0x2d, 0x2c,0x29,0x31,0x3b, 0x00,0x02,0x03,0x12,
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0x29, 0), // Display ON
	LCM_END
};

static const uint8_t cmd5CC0F1_init[] = {
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	// Frame Rate Control 1
	LCM_CMD(0xb1, 3), 0x04,0x10,0x10,
	LCM_CMD(0xb4, 1), 0x03,	// Display Inversion Control
	LCM_CMD(0xb6, 2), 0x17,0x00, // Display Function Setting
	// Power Control 1-3
	LCM_CMD(0xc0, 3), 0xa4,0x04,0x04,
	LCM_CMD(0xc1, 1), 0xc0,
	LCM_CMD(0xc2, 2), 0x0a,0x00,
	LCM_CMD(0xc5, 1), 0x0f, // VCOM Control 1
	//LCM_CMD(0x36, 1), 0xc8, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	// Set Gamma 1
	LCM_CMD(0xe0, 16), 0x02,0x1f,0x0b,0x12,
		0x36,0x33,0x2d,0x31, 0x2f,0x2c,0x33,0x3b, 0x00,0x02,0x01,0x02,
	// Set Gamma 2
	LCM_CMD(0xe1, 16), 0x02,0x1f,0x0b,0x12,
		0x36,0x32,0x2d,0x30, 0x2f,0x2c,0x33,0x3b, 0x00,0x01,0x00,0x02,
	LCM_CMD(0x29, 0), // Display ON
	//LCM_DELAY(120),
	LCM_END
};

static const uint8_t cmd5CA1F1_init[] = {
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	// Frame Rate Control 1-3
	LCM_CMD(0xb1, 3), 0x0f,0x04,0x04,
	LCM_CMD(0xb2, 3), 0x05,0x3a,0x3a,
	LCM_CMD(0xb3, 6), 0x05,0x3a,0x3a,0x05,0x3a,0x3a,
	LCM_CMD(0xb4, 1), 0x00,	// Display Inversion Control
	// Power Control 1-5
	LCM_CMD(0xc0, 3), 0xc3,0x06,0x44,
	LCM_CMD(0xc1, 1), 0xc2,
	LCM_CMD(0xc2, 2), 0x0d,0x00,
	LCM_CMD(0xc3, 2), 0xdb,0x2a,
	LCM_CMD(0xc4, 2), 0x8b,0xee,
	LCM_CMD(0xc5, 1), 0x0d, // VCOM Control 1
	//LCM_CMD(0x36, 1), 0x00, // Memory Access Control
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	// Set Gamma 1
	LCM_CMD(0xe0, 16), 0x13,0x14,0x06,0x11,
		0x29,0x26,0x21,0x26, 0x25,0x26,0x2e,0x3b, 0x00,0x03,0x02,0x06,
	// Set Gamma 2
	LCM_CMD(0xe1, 16), 0x02,0x25,0x06,0x11,
		0x29,0x26,0x21,0x26, 0x26,0x26,0x2e,0x3b, 0x00,0x03,0x02,0x06,
	LCM_CMD(0x29, 0), // Display ON
	//LCM_DELAY(120),
	LCM_END
};

static const uint8_t cmd333025_init[] = {
	//LCM_DELAY(120),
	LCM_CMD(0xff, 1), 0xa5,
	LCM_CMD(0x3e, 1), 0x08,
	LCM_CMD(0x3a, 1), 0x65, // Pixel Format Set
	LCM_CMD(0x82, 1), 0x00,
	LCM_CMD(0x98, 1), 0x00,
	LCM_CMD(0x63, 1), 0x0f,
	LCM_CMD(0x64, 1), 0x0f,
	LCM_CMD(0xb4, 1), 0x34,
	LCM_CMD(0xb5, 1), 0x30,
	LCM_CMD(0x83, 1), 0x13,
	LCM_CMD(0x86, 1), 0x04,
	LCM_CMD(0x87, 1), 0x16,
	LCM_CMD(0x88, 1), 0x28,
	LCM_CMD(0x89, 1), 0x2f,
	LCM_CMD(0x93, 1), 0x63,
	LCM_CMD(0x96, 1), 0x81,
	LCM_CMD(0xc3, 1), 0x11,
	LCM_CMD(0xe6, 1), 0x00,
	LCM_CMD(0x99, 1), 0x01,

#define X(i, a, b, c, d) \
	LCM_CMD(i, 1), a, \
	LCM_CMD(i + 1, 1), b, \
	LCM_CMD(i + 2, 1), c, \
	LCM_CMD(i + 3, 1), d
	// Gamma?
	X(0x70, 0x07,0x19,0x1a,0x13),
	X(0x74, 0x19,0x1d,0x47,0x0a),
	X(0x78, 0x07,0x47,0x05,0x09),
	X(0x7c, 0x0d,0x0c,0x0c,0x08),
	// Gamma?
	X(0xa0, 0x0b,0x36,0x09,0x0d),
	X(0xa4, 0x08,0x23,0x3b,0x04),
	X(0xa8, 0x07,0x38,0x0a,0x12),
	X(0xac, 0x0c,0x07,0x2f,0x07),
#undef X

	LCM_CMD(0xff, 1), 0x00,
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	//LCM_CMD(0x36, 1), 0xa8, // Memory Access Control
	LCM_CMD(0x29, 0), // Display ON
	LCM_DELAY(10),
	LCM_END
};

static const uint8_t cmd9102_nomi_init[] = {
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	//LCM_CMD(0x36, 1), 0xd0, // Memory Access Control
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	LCM_CMD(0xa8, 3), 0x02,0x00,0x00,
	LCM_CMD(0xa7, 1), 0x02,
	LCM_CMD(0xea, 1), 0x3a,
	LCM_CMD(0xb4, 1), 0x00, // Display Inversion Control
	LCM_CMD(0xff, 1), 0x12, // Power Control 4
	LCM_CMD(0xfd, 1), 0x08, // Power Control 3
	LCM_CMD(0xa4, 1), 0x09,	// Power Control 1
	LCM_CMD(0xe7, 2), 0x94,0x88,
	LCM_CMD(0xed, 1), 0x11, // Power Control 2
	LCM_CMD(0xe4, 1), 0xc5,
	LCM_CMD(0xe2, 1), 0x80,
	LCM_CMD(0xa3, 1), 0x09, // Frame Rate
	LCM_CMD(0xe3, 1), 0x07,
	LCM_CMD(0xe5, 1), 0x10,

	LCM_CMD(0xf0, 1), 0x70,	// Set Gamma 1
	LCM_CMD(0xf1, 1), 0x07,	// Set Gamma 2
	LCM_CMD(0xf2, 1), 0x00,	// Set Gamma 3
	LCM_CMD(0xf3, 1), 0x45,	// Set Gamma 4
	LCM_CMD(0xf4, 1), 0x00,	// Set Gamma 5
	LCM_CMD(0xf5, 1), 0x0c,	// Set Gamma 6
	// 0xf6 skipped
	LCM_CMD(0xf7, 1), 0x57,	// Set Gamma 7
	LCM_CMD(0xf8, 1), 0x44, // Set Gamma 8
	LCM_CMD(0xf9, 1), 0x66,	// Set Gamma 9
	LCM_CMD(0xfa, 1), 0x22,	// Set Gamma 10
	LCM_CMD(0xfb, 1), 0x04,	// Set Gamma 11
	LCM_CMD(0xfc, 1), 0x00,	// Set Gamma 12

	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x29, 0), // Display ON
	LCM_DELAY(50),
	LCM_END
};

static const uint8_t cmd9305_sigma_init[] = {
	LCM_CMD(0xfe, 0), // Inter Register Enable 1
	LCM_CMD(0xef, 0), // Inter Register Enable 2
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	//LCM_CMD(0x36, 1), 0x48, // Memory Access Control
	LCM_CMD(0xa4, 2), 0x44,0x44, // Vcore voltage Control
	LCM_CMD(0xa5, 2), 0x42,0x42,
	LCM_CMD(0xaa, 2), 0x88,0x88,
	LCM_CMD(0xe8, 2), 0x21,0x0b, // Frame Rate
	LCM_CMD(0xe3, 2), 0x01,0x18,
	LCM_CMD(0xe1, 2), 0x01,0x0a,
	LCM_CMD(0xac, 1), 0x00,
	LCM_CMD(0xad, 1), 0x33,
	LCM_CMD(0xae, 1), 0x2b,
	LCM_CMD(0xaf, 1), 0x55,
	LCM_CMD(0xa6, 2), 0x19,0x19, // Vreg1a voltage Control
	LCM_CMD(0xa7, 2), 0x27,0x27, // Vreg1b voltage Control
	LCM_CMD(0xa8, 2), 0x17,0x17, // Vreg2a voltage Control
	LCM_CMD(0xa9, 2), 0x26,0x26, // Vreg2b voltage Control
	LCM_CMD(0xf0, 6), 0x02,0x02,0x00,0x00,0x03,0x00, // Set Gamma 1
	LCM_CMD(0xf1, 6), 0x01,0x00,0x00,0x00,0x02,0x11, // Set Gamma 2
	LCM_CMD(0xf2, 6), 0x0a,0x0a,0x3a,0x03,0x04,0x53, // Set Gamma 3
	LCM_CMD(0xf3, 6), 0x0b,0x0a,0x30,0x06,0x04,0x3d, // Set Gamma 4
	LCM_CMD(0xf4, 6), 0x06,0x10,0x0f,0x30,0x3a,0x0f, // Set Gamma 5
	LCM_CMD(0xf5, 6), 0x0f,0x1d,0x1f,0x08,0x3a,0x0f, // Set Gamma 6
	LCM_CMD(0x35, 1), 0x00, // Tearing Effect Line ON
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x29, 0), // Display ON
	// LCM_CMD(0x2c, 0), // Memory Write
	LCM_END
};

static const uint8_t cmd5CB1F0_init[] = {
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(120),
	LCM_CMD(0x3a, 1), 0x05, // Pixel Format Set
	LCM_CMD(0xf0, 1), 0x01,
	LCM_CMD(0xf2, 1), 0xc0,
	LCM_CMD(0xff, 3), 0x40,0x03,0x1a,
	LCM_CMD(0xb1, 3), 0x04,0x04,0x03,
	LCM_CMD(0xb2, 3), 0x04,0x04,0x03,
	LCM_CMD(0xb3, 6), 0x04,0x04,0x03,0x04,0x04,0x03,
	LCM_CMD(0xb4, 1), 0x00,
	LCM_CMD(0xb6, 2), 0x17,0x00,
	LCM_CMD(0xc0, 2), 0x02,0x30,
	LCM_CMD(0xc1, 1), 0x05,
	LCM_CMD(0xc2, 2), 0x01,0x01,
	LCM_CMD(0xc3, 2), 0x01,0x01,
	LCM_CMD(0xc4, 2), 0x01,0x01,
	LCM_CMD(0xc5, 2), 0x3c,0x56,
	LCM_CMD(0xfc, 2), 0x11,0x17,
	//LCM_CMD(0x36, 1), 0xc8, // Memory Access Control
	// Set Gamma 1
	LCM_CMD(0xe0, 16), 0x03,0x20,0x10,0x24,0x29,0x20,0x18,0x1e,
		0x18,0x14,0x23,0x38,0x00,0x02,0x01,0x0a,
	// Set Gamma 2
	LCM_CMD(0xe1, 16), 0x04,0x20,0x10,0x2f,0x37,0x30,0x2c,0x31,
		0x33,0x33,0x39,0x38,0x00,0x02,0x01,0x0a,
	LCM_CMD(0x11, 0), // Sleep Out Mode
	LCM_DELAY(200),
	LCM_CMD(0x29, 0), // Display ON
	LCM_DELAY(120),
	LCM_END
};
#endif

static const lcd_config_t lcd_config[] = {
#if CHIP == 1
/* F+ F256 */

	// Sitronix ST7789
	{ 0x858552, 0xffffff, 0, 0, 1,  240, 320, 1, 0, 2,  { 60,  80,  90, 60, 80, 80 }, { 0 },  0x00, cmd8585_init },
	// GlaxyCore GC9305 (untested)
	{ 0x009305, 0xffffff, 0, 0, 1,  240, 320, 1, 0, 2,  { 30, 150, 150, 40, 50, 50 }, { 39000000 },  0x48, cmd9305_init },
	// GlaxyCore GC9306
	{ 0x009306, 0xffffff, 0, 0, 1,  240, 320, 1, 0, 2,  { 30, 150, 150, 40, 40, 40 }, { 39000000 },  0x48, cmd9306_init },
	// GlaxyCore GC9300 (untested)
	{ 0x009300, 0xffffff, 0, 0, 1,  240, 320, 1, 0, 2,  { 30, 150, 150, 40, 40, 40 }, { 0 },  0x48, cmd9300_init },

/* F+ Ezzy 4 */

	// GlaxyCore GC9102 (untested)
	{ 0x009102, 0xffffff, 0, 0, 1,  128, 160, 1, 0, 2,  { 60, 80, 90, 60, 80, 80 }, { 0 },  0xd0, cmd9102_init },
	// GlaxyCore GC9106
	{ 0x009106, 0xffffff, 0, 0, 1,  128, 160, 1, 0, 2,  { 60, 80, 90, 60, 80, 80 }, { 39000000 },  0xd0, cmd9106_init },

/* Nokia TA-1174 */

	// Sitronix ST7735
	{ 0x1c80f3, 0xffffff, 1, 2, 5,  128, 160, 0, 0, 2,  { 0 }, { 13000000 }, 0xd8, cmd1C80F3_init },
	// Sitronix ST7735 (from another factory)
	{ 0x7c80f3, 0xffffff, 1, 2, 5,  128, 160, 0, 0, 2,  { 0 }, { 13000000 }, 0xd8, cmd1C80F3_init },

/* BQ 3586 Tank Max */

	// RenesasSP R61529
	{ 0x01221529, 0xffffffff, 0, 0, 1,  320, 480, 1, 0, 2,  { 170, 170, 250, 8, 15, 15 }, { 0 }, 0x00, cmd1529_init },

/* DEXP SD2810 */

	// NewVision NV3029G
	{ 0x003033, 0xffffff, 0, 0, 1,  240, 320, 1, 0, 2,  { 10, 150, 100, 15, 35, 35 }, { 0 }, 0x08, cmd3033_init },

/* Nokia TA-1400 */

	// ??? (untested)
	{ 0x80f6, 0xffff, 1, 2, 5,  240, 320, 0, 0, 2,  { 0 }, { 52000000 }, 0x00, cmd80F6_init },
	// Sitronix ST7789 (untested)
	{ 0x8552, 0xffff, 1, 2, 5,  240, 320, 0, 0, 2,  { 0 }, { 52000000 }, 0x00, cmd8552_init },
	// GlaxyCore GC9304 (untested)
	{ 0x9304, 0xffff, 1, 2, 5,  240, 320, 0, 0, 2,  { 0 }, { 52000000 }, 0x48, cmd9304_init },
	// ??? (untested)
	{ 0x90fa, 0xffff, 1, 2, 5,  240, 320, 0, 0, 2,  { 0 }, { 52000000 }, 0x00, cmd90FA_init },
	// ???
	{ 0x9290f6, 0xffffff, 1, 2, 5,  240, 320, 0, 0, 2,  { 0 }, { 52000000 }, 0x00, cmd9290F6_init },

/* Samsung GT-E1272 (SC6531E) */

	// Sitronix ???
	{ 0x83760f, 0xffffff, 0, 0, 1,  128, 160, 1, 0, 0,  { 5, 150, 150, 10, 50, 50 }, { 0 }, 0xd0, cmd83760F_init },
#endif

#if CHIP == 2 || CHIP == 3
/* Joy's S21 */

	// GlaxyCore GC9106
	{ 0x009106, 0xffffff, 0, 0, 0,  128, 160, 1, 0, 2,  { 30, 150, 150, 40, 50, 50 }, { 0 },  0xd0, cmd9106_init },
	// GlaxyCore GC9108
	{ 0x009108, 0xffffff, 0, 0, 0,  128, 160, 1, 0, 2,  { 30, 150, 150, 40, 50, 50 }, { 0 },  0xd0, cmd9108_init },

/* Vector M115 */

	// Sitronix ST7735S CTC
	{ 0x7c89f0, 0xffffff, 0, 0, 1,  128 + 2, 128 + 3, 1, 0, 2,  { 15, 120, 75, 15, 35, 35 }, { 0 }, 0xc8, cmd7C89F0_init },

/* DZ09 */

	// GlaxyCore GC9307
	{ 0x80009307, 0xffffffff, 2, 17, 5,  240, 240, 0, 0, 2,  { 0 }, { 48000000 }, 0x48, cmd9307_init240 },

/* Itel it5626 */

	// GlaxyCore GC9307
	{ 0x009307, 0xffffff, 0, 0, 1,  240, 320, 1, 0, 2,  { 30, 150, 150, 40, 50, 50 }, { 0 }, 0x48, cmd9307_init },

/* Samsung B310E */

	// Sitronix ST7735 DTC (untested)
	{ 0x5cc0f1, 0xffffff, 0, 0, 1,  128, 160, 1, 0, 2,  { 15, 45, 90, 5, 15, 40 }, { 0 }, 0xc8, cmd5CC0F1_init },
	// Sitronix ST7735 TNM
	{ 0x5ca1f1, 0xffffff, 0, 0, 1,  128, 160, 1, 0, 2,  { 15, 45, 90, 5, 15, 40 }, { 0 }, 0x00, cmd5CA1F1_init },

/* Children's Camera (YX_Q5) */

	// NewVision NV3023
	{ 0x333025, 0xffffff, 0, 0, 1,  128, 160, 1, 0, 2,  { 45, 120, 120, 30, 80, 80 }, { 0 }, 0x08, cmd333025_init },

/* Nomi i184 */

	// GlaxyCore GC9102
	{ 0x009102, 0xffffff, 0, 0, 1,  128, 160, 1, 0, 2,  { 30, 120, 120, 40, 50, 50 }, { 0 },  0xd0, cmd9102_nomi_init },

/* Sigma mobile X-treme IO67 */

	// GlaxyCore GC9305
	{ 0x009305, 0xffffff, 0, 0, 1,  240, 320, 1, 0, 2,  { 50, 120, 75, 40, 50, 50 }, { 0 },  0x48, cmd9305_sigma_init },

/* Samsung GT-E1272 (SC6530) */

	// Sitronix ST7735 BYD (untested)
	{ 0x5cb1f0, 0xffffff, 0, 0, 1,  128, 160, 1, 0, 2,  { 15, 45, 90, 10, 30, 60 }, { 0 }, 0xc8, cmd5CB1F0_init },
#endif
};

