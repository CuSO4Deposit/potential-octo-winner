// 63 ms (< 66.67%), 35.83 MB (< 83.33 %)

#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize) {
    qsort(meetings, meetingsSize, sizeof(int*), compare);

    long long* room_available_time = (long long*)calloc(n, sizeof(long long));
    int* room_usage_count = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < meetingsSize; i++) {
        int start = meetings[i][0];
        int end = meetings[i][1];
        int duration = end - start;
        int best_room = -1;

        for (int j = 0; j < n; j++) {
            if (room_available_time[j] <= start) {
                best_room = j;
                break;
            }
        }

        if (best_room != -1) {
            room_available_time[best_room] = end;
            room_usage_count[best_room]++;
        } else {
            int room_to_use = -1;
            long long earliest_end_time = -1;

            for (int j = 0; j < n; j++) {
                if (room_to_use == -1 || room_available_time[j] < earliest_end_time) {
                    earliest_end_time = room_available_time[j];
                    room_to_use = j;
                }
            }
            room_available_time[room_to_use] += duration;
            room_usage_count[room_to_use]++;
        }
    }

    int max_meetings = 0;
    int result_room = 0;
    for (int i = 0; i < n; i++) {
        if (room_usage_count[i] > max_meetings) {
            max_meetings = room_usage_count[i];
            result_room = i;
        }
    }

    return result_room;
}
