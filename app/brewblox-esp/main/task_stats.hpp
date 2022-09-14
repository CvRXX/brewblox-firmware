#pragma once
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <stdio.h>
#include <stdlib.h>

void vTaskPrintRunTimeStats()
{
    TaskStatus_t* pxTaskStatusArray;
    volatile UBaseType_t uxArraySize, x;
    uint32_t ulTotalRunTime, ulStatsAsPercentage;

    // Take a snapshot of the number of tasks in case it changes while this
    // function is executing.
    uxArraySize = uxTaskGetNumberOfTasks();

    // Allocate a TaskStatus_t structure for each task.  An array could be
    // allocated statically at compile time.
    pxTaskStatusArray = static_cast<TaskStatus_t*>(pvPortMalloc(uxArraySize * sizeof(TaskStatus_t)));

    std::string header[] = {"Task",
                            "Min stack free",
                            "Core",
                            "CPU percentage"};
    for (auto& s : header) {
        fputs(s.c_str(), stdout);
        for (auto i = s.size(); i < 20; i++) {
            putchar(' ');
        }
    }
    putchar('\n');

    if (pxTaskStatusArray != NULL) {
        // Generate raw status information about each task.
        uxArraySize = uxTaskGetSystemState(pxTaskStatusArray, uxArraySize, &ulTotalRunTime);

        // For percentage calculations.
        ulTotalRunTime /= 100UL;

        // Avoid divide by zero errors.
        if (ulTotalRunTime > 0) {
            // For each populated position in the pxTaskStatusArray array,
            // format the raw data as human readable ASCII data
            for (x = 0; x < uxArraySize; x++) {
                // What percentage of the total run time has the task used?
                // This will always be rounded down to the nearest integer.
                // ulTotalRunTimeDiv100 has already been divided by 100.
                ulStatsAsPercentage = pxTaskStatusArray[x].ulRunTimeCounter / ulTotalRunTime;

                // print task name and spaces for equal width
                fputs(pxTaskStatusArray[x].pcTaskName, stdout);
                for (auto i = strlen(pxTaskStatusArray[x].pcTaskName); i < 20; i++) {
                    putchar(' ');
                }

                auto printed = printf("%u", pxTaskStatusArray[x].usStackHighWaterMark);
                for (auto i = printed; i < 20; i++) {
                    putchar(' ');
                }

                printed = printf("%d", pxTaskStatusArray[x].xCoreID);
                for (auto i = printed; i < 20; i++) {
                    putchar(' ');
                }

                if (ulStatsAsPercentage > 0UL) {
                    printf("%u%%\n", ulStatsAsPercentage);
                } else {
                    // If the percentage is zero here then the task has
                    // consumed less than 1% of the total run time.
                    printf("<1%%\n");
                }
            }
        }
        putchar('\n');
        // The array is no longer needed, free the memory it consumes.
        vPortFree(pxTaskStatusArray);
    }
}
