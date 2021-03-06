/******************************************************************************
 * Copyright 2020 The Firmament Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef __SENSOR_MANAGER_H__
#define __SENSOR_MANAGER_H__

#include <firmament.h>

#define RAW_TEMPERATURE_POS			0
#define RAW_PRESSURE_POS			1
#define COLLECT_DATA_POS			2
#define GYR_RAW_POS					0
#define GYR_SCALE_POS				1
#define ACC_RAW_POS					2
#define ACC_SCALE_POS				3
#define MAG_RAW_POS					4
#define MAG_SCLAE_POS				5

//common cmd
#define SENSOR_GET_DEVICE_ID		0x00
//acc,mag cmd
#define SENSOR_SET_ACC_RANGE		0x01
#define SENSOR_SET_ACC_SAMPLERATE	0x02
#define SENSOR_SET_MAG_RANGE		0x03
#define SENSOR_SET_MAG_SAMPLERATE	0x04
//gyr cmd
#define SENSOR_SET_GYR_RANGE		0x20
//baro cmd
#define SENSOR_CONVERSION			0x30
#define SENSOR_IS_CONV_FIN			0x31

typedef struct {
	uint32_t timestamp_ms;
	float gyr_B_radDs[3];
	float acc_B_mDs2[3];
} IMU_Report;

typedef struct {
	uint32_t timestamp_ms;
	float mag_B_gauss[3];
} Mag_Report;

typedef struct {
	uint32_t timestamp_ms;
	float temperature_deg;
	int32_t pressure_pa;
	float altitude_m;
} Baro_Report;

typedef struct {
	uint32_t timestamp_ms;
	int32_t lon;
	int32_t lat;
	int32_t height;
	float hAcc;
	float vAcc;
	float velN;
	float velE;
	float velD;
	float sAcc;
	uint8_t fixType;
	uint8_t numSV;
	uint16_t reserved;
} GPS_Report;

rt_err_t sensor_manager_init(void);
void sensor_collect(void);

#endif
