/*
 *    Copyright 2020 Piyush Shah <shahpiyushv@gmail.com>
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#include <stdio.h>
#include <string.h>
//#include <C:\source\repos\json-parser\include\json_parser.h>
#include "..\include\json_parser.h"

//#define json_test_str	"{\n\"str_val\" :    \"JSON Parser\",\n" \
//			"\t\"float_val\" : 2.0,\n" \
//			"\"int_val\" : 2017,\n" \
//			"\"bool_val\" : false,\n" \
//			"\"supported_el\" :\t [\"bool\",\"int\","\
//			"\"float\",\"str\"" \
//			",\"object\",\"array\"],\n" \
//			"\"features\" : { \"objects\":true, "\
//			"\"arrays\":\"yes\"},\n"\
//			"\"int_64\":109174583252}"

#define alarm_config_json "{\n\
  \"zones\": [\n\
    {\n\
      \"zName\": \"Front Door\",\n\
      \"zBRD\": 0,\n\
      \"zID\": 0,\n\
      \"zType\": \"ENTRY_DELAY1\",\n\
      \"zPartn\": 1,\n\
      \"zAlarmT\": \"STEADY_ALARM\",\n\
      \"zShdnEn\": false,\n\
      \"zBypEn\": true,\n\
      \"zStayZ\": true,\n\
      \"zFrceEn\": true,\n\
      \"zIntelZ\": false,\n\
      \"zDlyTRM\": false,\n\
      \"zTmprGlb\": true,\n\
      \"zTmprOPT\": \"TROUBLE_ONLY\",\n\
      \"zAmskGlb\": true,\n\
      \"zAmskOpt\": \"DISABLE\"\n\
    },\n\
    {\n\
      \"zName\": \"Back Door\",\n\
      \"zBRD\": 0,\n\
      \"zID\": 1,\n\
      \"zType\": \"ENTRY_DELAY2\",\n\
      \"zPartn\": 1,\n\
      \"zAlarmT\": \"PULSED_ALARM\",\n\
      \"zShdnEn\": false,\n\
      \"zBypEn\": true,\n\
      \"zStayZ\": true,\n\
      \"zFrceEn\": true,\n\
      \"zIntelZ\": false,\n\
      \"zDlyTRM\": false,\n\
      \"zTmprGlb\": true,\n\
      \"zTmprOPT\": \"TROUBLE_ONLY\",\n\
      \"zAmskGlb\": true,\n\
      \"zAmskOpt\": \"DISABLE\"\n\
    },\n\
    {\n\
      \"zName\": \"Motion Sensor Living Room\",\n\
      \"zBRD\": 0,\n\
      \"zID\": 2,\n\
      \"zType\": \"FOLLOW\",\n\
      \"zPartn\": 1,\n\
      \"zAlarmT\": \"STEADY_ALARM\",\n\
      \"zShdnEn\": false,\n\
      \"zBypEn\": true,\n\
      \"zStayZ\": false,\n\
      \"zFrceEn\": true,\n\
      \"zIntelZ\": true,\n\
      \"zDlyTRM\": false,\n\
      \"zTmprGlb\": true,\n\
      \"zTmprOPT\": \"ALARM\",\n\
      \"zAmskGlb\": true,\n\
      \"zAmskOpt\": \"ALARM_WHEN_ARMED\"\n\
    },\n\
    {\n\
      \"zName\": \"Window Sensor Bedroom\",\n\
      \"zBRD\": 0,\n\
      \"zID\": 3,\n\
      \"zType\": \"INSTANT\",\n\
      \"zPartn\": 2,\n\
      \"zAlarmT\": \"SILENT_ALARM\",\n\
      \"zShdnEn\": false,\n\
      \"zBypEn\": true,\n\
      \"zStayZ\": false,\n\
      \"zFrceEn\": true,\n\
      \"zIntelZ\": false,\n\
      \"zDlyTRM\": false,\n\
      \"zTmprGlb\": false,\n\
      \"zTmprOPT\": \"DISABLE\",\n\
      \"zAmskGlb\": false,\n\
      \"zAmskOpt\": \"DISABLE\"\n\
    },\n\
    {\n\
      \"zName\": \"Smoke Detector\",\n\
      \"zBRD\": 0,\n\
      \"zID\": 4,\n\
      \"zType\": \"H24_FIRE_STANDARD\",\n\
      \"zPartn\": 2,\n\
      \"zAlarmT\": \"STEADY_ALARM\",\n\
      \"zShdnEn\": false,\n\
      \"zBypEn\": false,\n\
      \"zStayZ\": false,\n\
      \"zFrceEn\": false,\n\
      \"zIntelZ\": false,\n\
      \"zDlyTRM\": false,\n\
      \"zTmprGlb\": true,\n\
      \"zTmprOPT\": \"TROUBLE_ONLY\",\n\
      \"zAmskGlb\": true,\n\
      \"zAmskOpt\": \"TROUBLE_ONLY\"\n\
    }\n\
  ],\n\
  \"partitions\": [\n\
    {\n\
      \"pName\": \"Main Floor\",\n\
      \"pIdx\": 1,\n\
      \"pValid\": true,\n\
      \"pFrceOnRegArm\": true,\n\
      \"pFrceOnStayArm\": true,\n\
      \"pED2znFollow\": true,\n\
      \"pAlrmOutEn\": true,\n\
      \"pAlrmTime\": 120,\n\
      \"pNoCutOnFire\": true,\n\
      \"pAlrmRecTime\": 30,\n\
      \"pED1Intvl\": 30,\n\
      \"pED2Intvl\": 45,\n\
      \"pExitDly\": 60,\n\
      \"pFollow1\": 1,\n\
      \"pFollow2\": 0,\n\
      \"pFollow3\": 0,\n\
      \"pFollow4\": 0,\n\
      \"pFollow5\": 0,\n\
      \"pFollow6\": 0,\n\
      \"pFollow7\": 0,\n\
      \"pFollow8\": 0\n\
    },\n\
    {\n\
      \"pName\": \"Upper Floor\",\n\
      \"pIdx\": 2,\n\
      \"pValid\": true,\n\
      \"pFrceOnRegArm\": true,\n\
      \"pFrceOnStayArm\": false,\n\
      \"pED2znFollow\": true,\n\
      \"pAlrmOutEn\": true,\n\
      \"pAlrmTime\": 120,\n\
      \"pNoCutOnFire\": true,\n\
      \"pAlrmRecTime\": 30,\n\
      \"pED1Intvl\": 30,\n\
      \"pED2Intvl\": 45,\n\
      \"pExitDly\": 60,\n\
      \"pFollow1\": 0,\n\
      \"pFollow2\": 0,\n\
      \"pFollow3\": 0,\n\
      \"pFollow4\": 0,\n\
      \"pFollow5\": 0,\n\
      \"pFollow6\": 0,\n\
      \"pFollow7\": 0,\n\
      \"pFollow8\": 0\n\
    }\n\
  ],\n\
  \"globalOptions\": {\n\
    \"MaxSlaves\": 2,\n\
    \"RestrSprvsL\": true,\n\
    \"RestrTamper\": true,\n\
    \"RestrACfail\": false,\n\
    \"RestrBatFail\": true,\n\
    \"RestrOnBell\": false,\n\
    \"RestrOnBrdFail\": true,\n\
    \"RestrOnAmask\": false,\n\
    \"TroubleLatch\": true,\n\
    \"TamperBpsOpt\": false,\n\
    \"TamperOpts\": \"TROUBLE_ONLY\",\n\
    \"AntiMaskOpt\": \"ALARM_WHEN_ARMED\",\n\
    \"RfSprvsOpt\": \"ALARM\",\n\
    \"SprvsLoss\": 0,\n\
    \"ACfail\": 0,\n\
    \"BatFail\": 0,\n\
    \"BellFail\": 0,\n\
    \"BrdFail\": 0\n\
  },\n\
  \"pgms\": [\n\
    {\n\
      \"pgmName\": \"External Siren\",\n\
      \"pgmBrd\": 0,\n\
      \"pgmID\": 0,\n\
      \"pgmPulseLen\": 5,\n\
      \"pgmValid\": true\n\
    },\n\
    {\n\
      \"pgmName\": \"Garage Door\",\n\
      \"pgmBrd\": 0,\n\
      \"pgmID\": 1,\n\
      \"pgmPulseLen\": 3,\n\
      \"pgmValid\": true\n\
    },\n\
    {\n\
      \"pgmName\": \"Entrance Light\",\n\
      \"pgmBrd\": 0,\n\
      \"pgmID\": 2,\n\
      \"pgmPulseLen\": 0,\n\
      \"pgmValid\": true\n\
    }\n\
  ],\n\
  \"keyswitches\": [\n\
    {\n\
      \"kswName\": \"Front Door Keyswitch\",\n\
      \"partition\": 0,\n\
      \"type\": \"MAINTAINED\",\n\
      \"action\": \"REGULAR_ARM_ONLY\",\n\
      \"boardID\": 0,\n\
      \"zoneID\": 5\n\
    }\n\
  ]\n\
}"

// #define alarm_config_json "{\"zones\":[{\"zName\":\"Front\"},{\"zName\":\"Back\"}]}"

int main(int argc, char** argv)
{
    jparse_ctx_t jctx, tmp_jctx;

    int ret = json_parse_start(&jctx, alarm_config_json, strlen(alarm_config_json));
    if (ret != OS_SUCCESS) {
        printf("Parser failed\n");
        return -1;
    }

    char str_val[128];
    int int_val, num_elem;
    bool bool_val;

    // Parse and display global options
    if (json_obj_get_object(&jctx, "globalOptions") == OS_SUCCESS) {
        printf("\n===== Global Options =====\n");

        if (json_obj_get_int(&jctx, "MaxSlaves", &int_val) == OS_SUCCESS)
            printf("MaxSlaves: %d\n", int_val);

        if (json_obj_get_bool(&jctx, "RestrSprvsL", &bool_val) == OS_SUCCESS)
            printf("RestrSprvsL: %s\n", bool_val ? "true" : "false");

        if (json_obj_get_bool(&jctx, "RestrTamper", &bool_val) == OS_SUCCESS)
            printf("RestrTamper: %s\n", bool_val ? "true" : "false");

        if (json_obj_get_string(&jctx, "TamperOpts", str_val, sizeof(str_val)) == OS_SUCCESS)
            printf("TamperOpts: %s\n", str_val);

        json_obj_leave_object(&jctx);
    }

    // Parse and display zones
    if (json_obj_get_array(&jctx, "zones", &num_elem) == OS_SUCCESS) {
        printf("\n===== Zones (%d) =====\n", num_elem);
        tmp_jctx = jctx;                                // needed to properly parse arrays
        for (int i = 0; i < num_elem; i++) {
			jctx = tmp_jctx;
            if (json_arr_get_object(&jctx, i) == OS_SUCCESS) {
                printf("\nZone %d:\n", i + 1);

                if (json_obj_get_int(&jctx, "zID", &int_val) == OS_SUCCESS)
                    printf("  ID: %d\n", int_val);

                if (json_obj_get_string(&jctx, "zName", str_val, sizeof(str_val)) == OS_SUCCESS)
                    printf("  Name: %s\n", str_val);

                if (json_obj_get_string(&jctx, "zType", str_val, sizeof(str_val)) == OS_SUCCESS)
                    printf("  Type: %s\n", str_val);

                if (json_obj_get_int(&jctx, "zPartn", &int_val) == OS_SUCCESS)
                    printf("  Partition: %d\n", int_val);

                if (json_obj_get_bool(&jctx, "zBypEn", &bool_val) == OS_SUCCESS)
                    printf("  Bypass Enabled: %s\n", bool_val ? "true" : "false");

                json_obj_leave_object(&jctx);
            }
        }
       json_obj_leave_array(&jctx);
    }

    // Parse and display partitions
    if (json_obj_get_array(&jctx, "partitions", &num_elem) == OS_SUCCESS) {
        printf("\n===== Partitions (%d) =====\n", num_elem);
        tmp_jctx = jctx;
        for (int i = 0; i < num_elem; i++) {
            jctx = tmp_jctx;
            if (json_arr_get_object(&jctx, i) == OS_SUCCESS) {
                printf("\nPartition %d:\n", i + 1);

                if (json_obj_get_string(&jctx, "pName", str_val, sizeof(str_val)) == OS_SUCCESS)
                    printf("  Name: %s\n", str_val);

                if (json_obj_get_int(&jctx, "pIdx", &int_val) == OS_SUCCESS)
                    printf("  Index: %d\n", int_val);

                if (json_obj_get_int(&jctx, "pExitDly", &int_val) == OS_SUCCESS)
                    printf("  Exit Delay: %d seconds\n", int_val);

                if (json_obj_get_int(&jctx, "pED1Intvl", &int_val) == OS_SUCCESS)
                    printf("  Entry Delay 1: %d seconds\n", int_val);

                json_obj_leave_object(&jctx);
            }
        }
        json_obj_leave_array(&jctx);
    }

    // Parse and display pgms
    if (json_obj_get_array(&jctx, "pgms", &num_elem) == OS_SUCCESS) {
        printf("\n===== PGMs (%d) =====\n", num_elem);
        tmp_jctx = jctx;
        for (int i = 0; i < num_elem; i++) {
            jctx = tmp_jctx;
            if (json_arr_get_object(&jctx, i) == OS_SUCCESS) {
                printf("\nPGM %d:\n", i + 1);

                if (json_obj_get_string(&jctx, "pgmName", str_val, sizeof(str_val)) == OS_SUCCESS)
                    printf("  Name: %s\n", str_val);

                if (json_obj_get_int(&jctx, "pgmID", &int_val) == OS_SUCCESS)
                    printf("  ID: %d\n", int_val);

                if (json_obj_get_int(&jctx, "pgmPulseLen", &int_val) == OS_SUCCESS)
                    printf("  Pulse Length: %d seconds\n", int_val);

                json_obj_leave_object(&jctx);
            }
        }
        json_obj_leave_array(&jctx);
    }

    // Parse and display keyswitches
    if (json_obj_get_array(&jctx, "keyswitches", &num_elem) == OS_SUCCESS) {
        printf("\n===== Keyswitches (%d) =====\n", num_elem);
        tmp_jctx = jctx;
        for (int i = 0; i < num_elem; i++) {
            jctx = tmp_jctx;
            if (json_arr_get_object(&jctx, i) == OS_SUCCESS) {
                printf("\nKeyswitch %d:\n", i + 1);

                if (json_obj_get_string(&jctx, "kswName", str_val, sizeof(str_val)) == OS_SUCCESS)
                    printf("  Name: %s\n", str_val);

                if (json_obj_get_string(&jctx, "type", str_val, sizeof(str_val)) == OS_SUCCESS)
                    printf("  Type: %s\n", str_val);

                if (json_obj_get_string(&jctx, "action", str_val, sizeof(str_val)) == OS_SUCCESS)
                    printf("  Action: %s\n", str_val);

                json_obj_leave_object(&jctx);
            }
        }
        json_obj_leave_array(&jctx);
    }

    json_parse_end(&jctx);
    return 0;
}


//int main(int argc, char **argv)
//{
//	jparse_ctx_t jctx;
//	int ret = json_parse_start(&jctx, json_test_str, strlen(json_test_str));
//	if (ret != OS_SUCCESS) {
//		printf("Parser failed\n");
//		return -1;
//	}
//	char str_val[64];
//	int int_val, num_elem;
//	int64_t int64_val;
//	bool bool_val;
//	float float_val;
//
//	if (json_obj_get_string(&jctx, "str_val", str_val, sizeof(str_val)) == OS_SUCCESS)
//		printf("str_val %s\n", str_val);
//
//	if (json_obj_get_float(&jctx, "float_val", &float_val) == OS_SUCCESS)
//		printf("float_val %f\n", float_val);
//
//	if (json_obj_get_int(&jctx, "int_val", &int_val) == OS_SUCCESS)
//		printf("int_val %d\n", int_val);
//
//	if (json_obj_get_bool(&jctx, "bool_val", &bool_val) == OS_SUCCESS)
//		printf("bool_val %s\n", bool_val ? "true" : "false");
//
//	if (json_obj_get_array(&jctx, "supported_el", &num_elem) == OS_SUCCESS) {
//		printf("Array has %d elements\n", num_elem);
//		int i;
//		for (i = 0; i < num_elem; i++) {
//			json_arr_get_string(&jctx, i, str_val, sizeof(str_val));
//			printf("index %d: %s\n", i, str_val);
//		}
//		json_obj_leave_array(&jctx);
//	}
//	if (json_obj_get_object(&jctx, "features") == OS_SUCCESS) {
//		printf("Found object\n");
//		if (json_obj_get_bool(&jctx, "objects", &bool_val) == OS_SUCCESS)
//			printf("objects %s\n", bool_val ? "true" : "false");
//		if (json_obj_get_string(&jctx, "arrays", str_val, sizeof(str_val)) == OS_SUCCESS)
//			printf("arrays %s\n", str_val);
//		json_obj_leave_object(&jctx);
//	}
//	if (json_obj_get_int64(&jctx, "int_64", &int64_val) == OS_SUCCESS)
//		printf("int64_val %lld\n", int64_val);
//
//	json_parse_end(&jctx);
//	return 0;
//
//}
