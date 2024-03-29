char* map_debug[] = {
	//00
	"NOP",
	"LDBCnn",
	"LDBCmA",
	"INCBC",

	"INCr_b",
	"DECr_b",
	"LDrn_b",
	"RLCA",

	"XX",
	"ADDHLBC",
	"LDABCm",
	"DECBC",

	"INCr_c",
	"DECr_c",
	"LDrn_c",
	"RRCA",

	//10
	"DJNZn",
	"LDDEnn",
	"LDDEmA",
	"INCDE",

	"INCr_d",
	"DECr_d",
	"LDrn_d",
	"RLA",

	"JRn",
	"ADDHLDE",
	"LDADEm",
	"DECDE",

	"INCr_e",
	"DECr_e",
	"LDrn_e",
	"RRA",

	//20
	"JRNZn",
	"LDHLnn",
	"LDHLIA",
	"INCHL",

	"INCr_h",
	"DECr_h",
	"LDrn_h",
	"DAA",

	"JRZn",
	"ADDHLHL",
	"LDAHLI",
	"DECHL",

	"INCr_l",
	"DECr_l",
	"LDrn_l",
	"CPL",

	//30
	"JRNCn",
	"LDSPnn",
	"LDHLDA",
	"INCSP",

	"INCHLm",
	"DECHLm",
	"LDHLmn",
	"SCF",

	"JRCn",
	"ADDHLSP",
	"LDAHLD",
	"DECSP",

	"INCr_a",
	"DECr_a",
	"LDrn_a",
	"CCF",

	//40
	"LDrr_bb",
	"LDrr_bc",
	"LDrr_bd",
	"LDrr_be",

	"LDrr_bh",
	"LDrr_bl",
	"LDrHLm_b",
	"LDrr_ba",

	"LDrr_cb",
	"LDrr_cc",
	"LDrr_cd",
	"LDrr_ce",

	"LDrr_ch",
	"LDrr_cl",
	"LDrHLm_c",
	"LDrr_ca",

	//50
	"LDrr_db",
	"LDrr_dc",
	"LDrr_dd",
	"LDrr_de",

	"LDrr_dh",
	"LDrr_dl",
	"LDrHLm_d",
	"LDrr_da",

	"LDrr_eb",
	"LDrr_ec",
	"LDrr_ed",
	"LDrr_ee",

	"LDrr_eh",
	"LDrr_el",
	"LDrHLm_e",
	"LDrr_ea",

	//60
	"LDrr_hb",
	"LDrr_hc",
	"LDrr_hd",
	"LDrr_he",

	"LDrr_hh",
	"LDrr_hl",
	"LDrHLm_h",
	"LDrr_ha",

	"LDrr_lb",
	"LDrr_lc",
	"LDrr_ld",
	"LDrr_le",

	"LDrr_lh",
	"LDrr_ll",
	"LDrHLm_l",
	"LDrr_la",

	//70
	"LDHLmr_b",
	"LDHLmr_c",
	"LDHLmr_d",
	"LDHLmr_e",

	"LDHLmr_h",
	"LDHLmr_l",
	"HALT",
	"LDHLmr_a",

	"LDrr_ab",
	"LDrr_ac",
	"LDrr_ad",
	"LDrr_ae",

	"LDrr_ah",
	"LDrr_al",
	"LDrHLm_a",
	"LDrr_aa",

	//80
	"ADDr_b",
	"ADDr_c",
	"ADDr_d",
	"ADDr_e",

	"ADDr_h",
	"ADDr_l",
	"ADDHL",
	"ADDr_a",

	"ADCr_b",
	"ADCr_c",
	"ADCr_d",
	"ADCr_e",

	"ADCr_h",
	"ADCr_l",
	"ADCHL",
	"ADCr_a",

	//90
	"SUBr_b",
	"SUBr_c",
	"SUBr_d",
	"SUBr_e",

	"SUBr_h",
	"SUBr_l",
	"SUBHL",
	"SUBr_a",

	"SBCr_b",
	"SBCr_c",
	"SBCr_d",
	"SBCr_e",

	"SBCr_h",
	"SBCr_l",
	"SBCHL",
	"SBCr_a",

	//A0
	"ANDr_b",
	"ANDr_c",
	"ANDr_d",
	"ANDr_e",

	"ANDr_h",
	"ANDr_l",
	"ANDHL",
	"ANDr_a",

	"XORr_b",
	"XORr_c",
	"XORr_d",
	"XORr_e",

	"XORr_h",
	"XORr_l",
	"XORHL",
	"XORr_a",

	//B0
	"ORr_b",
	"ORr_c",
	"ORr_d",
	"ORr_e",

	"ORr_h",
	"ORr_l",
	"ORHL",
	"ORr_a",

	"CPr_b",
	"CPr_c",
	"CPr_d",
	"CPr_e",

	"CPr_h",
	"CPr_l",
	"CPHL",
	"CPr_a",

	//C0
	"RETNZ",
	"POPBC",
	"JPNZnn",
	"JPnn",

	"CALLNZnn",
	"PUSHBC",
	"ADDn",
	"RST00",

	"RETZ",
	"RET",
	"JPZnn",
	"XX",

	"CALLZnn",
	"CALLnn",
	"ADCn",
	"RST08",

	//D0
	"RETNC",
	"POPDE",
	"JPNCnn",
	"XX",

	"CALLNCnn",
	"PUSHDE",
	"SUBn",
	"RST10",

	"RETC",
	"RETI",
	"JPCnn",
	"XX",

	"CALLCnn",
	"XX",
	"SBCn",
	"RST18",

	//E0
	"LDIOnA",
	"POPHL",
	"LDIOCA",
	"XX",

	"XX",
	"PUSHHL",
	"ANDn",
	"RST20",

	"ADDSPn",
	"JPHL",
	"LDmmA",
	"XX",

	"XX",
	"XX",
	"XORn",
	"RST28",

	//F0
	"LDAIOn",
	"POPAF",
	"LDAIOC",
	"DI",

	"XX",
	"PUSHAF",
	"ORn",
	"RST30",

	"LDHLSPn",
	"XX",
	"LDAmm",
	"EI",

	"XX",
	"XX",
	"CPn",
	"RST38"
};

char* cbmap_debug[] = {
	//CB00
	"RLCr_b",
	"RLCr_c",
	"RLCr_d",
	"RLCr_e",

	"RLCr_h",
	"RLCr_l",
	"RLCHL",
	"RLCr_a",

	"RRCr_b",
	"RRCr_c",
	"RRCr_d",
	"RRCr_e",

	"RRCr_h",
	"RRCr_l",
	"RRCHL",
	"RRCr_a",

	//CB10
	"RLr_b",
	"RLr_c",
	"RLr_d",
	"RLr_e",

	"RLr_h",
	"RLr_l",
	"RLHL",
	"RLr_a",

	"RRr_b",
	"RRr_c",
	"RRr_d",
	"RRr_e",

	"RRr_h",
	"RRr_l",
	"RRHL",
	"RRr_a",

	//CB20
	"SLAr_b",
	"SLAr_c",
	"SLAr_d",
	"SLAr_e",

	"SLAr_h",
	"SLAr_l",
	"XX",
	"SLAr_a",

	"SRAr_b",
	"SRAr_c",
	"SRAr_d",
	"SRAr_e",

	"SRAr_h",
	"SRAr_l",
	"XX",
	"SRAr_a",

	//CB30
	"SWAPr_b",
	"SWAPr_c",
	"SWAPr_d",
	"SWAPr_e",

	"SWAPr_h",
	"SWAPr_l",
	"XX",
	"SWAPr_a",

	"SRLr_b",
	"SRLr_c",
	"SRLr_d",
	"SRLr_e",

	"SRLr_h",
	"SRLr_l",
	"XX",
	"SRLr_a",

	//CB40
	"BIT0b",
	"BIT0c",
	"BIT0d",
	"BIT0e",

	"BIT0h",
	"BIT0l",
	"BIT0m",
	"BIT0a",

	"BIT1b",
	"BIT1c",
	"BIT1d",
	"BIT1e",

	"BIT1h",
	"BIT1l",
	"BIT1m",
	"BIT1a",

	//CB50
	"BIT2b",
	"BIT2c",
	"BIT2d",
	"BIT2e",

	"BIT2h",
	"BIT2l",
	"BIT2m",
	"BIT2a",

	"BIT3b",
	"BIT3c",
	"BIT3d",
	"BIT3e",

	"BIT3h",
	"BIT3l",
	"BIT3m",
	"BIT3a",

	//CB60
	"BIT4b",
	"BIT4c",
	"BIT4d",
	"BIT4e",

	"BIT4h",
	"BIT4l",
	"BIT4m",
	"BIT4a",

	"BIT5b",
	"BIT5c",
	"BIT5d",
	"BIT5e",

	"BIT5h",
	"BIT5l",
	"BIT5m",
	"BIT5a",

	//CB70
	"BIT6b",
	"BIT6c",
	"BIT6d",
	"BIT6e",

	"BIT6h",
	"BIT6l",
	"BIT6m",
	"BIT6a",

	"BIT7b",
	"BIT7c",
	"BIT7d",
	"BIT7e",

	"BIT7h",
	"BIT7l",
	"BIT7m",
	"BIT7a",

	//CB80
	"RES0b",
	"RES0c",
	"RES0d",
	"RES0e",

	"RES0h",
	"RES0l",
	"RES0m",
	"RES0a",

	"RES1b",
	"RES1c",
	"RES1d",
	"RES1e",

	"RES1h",
	"RES1l",
	"RES1m",
	"RES1a",

	//CB90
	"RES2b",
	"RES2c",
	"RES2d",
	"RES2e",

	"RES2h",
	"RES2l",
	"RES2m",
	"RES2a",

	"RES3b",
	"RES3c",
	"RES3d",
	"RES3e",

	"RES3h",
	"RES3l",
	"RES3m",
	"RES3a",

	//CBA0
	"RES4b",
	"RES4c",
	"RES4d",
	"RES4e",

	"RES4h",
	"RES4l",
	"RES4m",
	"RES4a",

	"RES5b",
	"RES5c",
	"RES5d",
	"RES5e",

	"RES5h",
	"RES5l",
	"RES5m",
	"RES5a",

	//CBB0
	"RES6b",
	"RES6c",
	"RES6d",
	"RES6e",

	"RES6h",
	"RES6l",
	"RES6m",
	"RES6a",

	"RES7b",
	"RES7c",
	"RES7d",
	"RES7e",

	"RES7h",
	"RES7l",
	"RES7m",
	"RES7a",

	//CBC0
	"SET0b",
	"SET0c",
	"SET0d",
	"SET0e",

	"SET0h",
	"SET0l",
	"SET0m",
	"SET0a",

	"SET1b",
	"SET1c",
	"SET1d",
	"SET1e",

	"SET1h",
	"SET1l",
	"SET1m",
	"SET1a",

	//CBD0
	"SET2b",
	"SET2c",
	"SET2d",
	"SET2e",

	"SET2h",
	"SET2l",
	"SET2m",
	"SET2a",

	"SET3b",
	"SET3c",
	"SET3d",
	"SET3e",

	"SET3h",
	"SET3l",
	"SET3m",
	"SET3a",

	//CBE0
	"SET4b",
	"SET4c",
	"SET4d",
	"SET4e",

	"SET4h",
	"SET4l",
	"SET4m",
	"SET4a",

	"SET5b",
	"SET5c",
	"SET5d",
	"SET5e",

	"SET5h",
	"SET5l",
	"SET5m",
	"SET5a",

	//CBF0
	"SET6b",
	"SET6c",
	"SET6d",
	"SET6e",

	"SET6h",
	"SET6l",
	"SET6m",
	"SET6a",

	"SET7b",
	"SET7c",
	"SET7d",
	"SET7e",

	"SET7h",
	"SET7l",
	"SET7m",
	"SET7a"
};