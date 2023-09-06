#ifndef __SC7A20REG_H
#define __SC7A20REG_H
//	Reserved(do not modify)		0X00~0X0B标识为“保留”的，在使用中不要更改，可能会引起永久性破坏。

#define	OUT_TEMP_L		0x0C
#define	OUT_TEMP_H		0X0D
#define	Reserved	    0X0E
#define	WHO_AM_I        0X0F

//#define	USER_CAL        0X13 ~ 0X1A

#define	NVM_WR          0X1E
#define	TEMP_CFG        0X1F
#define	CTRL_REG1       0X20
#define	CTRL_REG2       0X21
#define	CTRL_REG3       0X22
#define	CTRL_REG4       0X23
#define	CTRL_REG5       0X24
#define	CTRL_REG6       0X25
#define	REFERENCE       0X26
#define	STATUS_REG      0X27
#define	OUT_X_L         0X28
#define	OUT_X_H         0X29
#define	OUT_Y_L         0X2A
#define	OUT_Y_H         0X2B
#define	OUT_Z_L         0X2C
#define	OUT_Z_H         0X2D
#define	FIFO_CTRL_REG   0X2E
#define	FIFO_SRC_REG    0X2F
#define	INT1_CFG        0X30
#define	INT1_SOURCE     0X31
#define	INT1_THS        0X32
#define	INT1_DURATION   0X33
#define	INT2_CFG        0X34
#define	INT2_SOURCE     0X35
#define	INT2_THS        0X36
#define	INT2_DURATION   0X37
#define	CLICK_CFG       0X38
#define	CLICK_SRC       0X39
#define	CLICK_THS       0X3A
#define	TIME_LIMIT      0X3B
#define	TIME_LATENCY    0X3C
#define	TIME_WINDOW     0X3D
#define	ACT_THS         0X3E
#define	ACT_DURATION    0X3F

#endif
