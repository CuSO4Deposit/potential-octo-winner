// 51 ms (< 100%), 35.92 MB (< 33.33%)

#include <stdlib.h>

typedef struct {
    long long time;
    int room;
} HeapNode;

typedef struct {
    HeapNode* nodes;
    int size;
    int capacity;
} MinHeap;

void swap_nodes(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

MinHeap* create_heap(int capacity) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->nodes = (HeapNode*)malloc(sizeof(HeapNode) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void heapify_down(MinHeap* h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < h->size && (h->nodes[left].time < h->nodes[smallest].time ||
                           (h->nodes[left].time == h->nodes[smallest].time && h->nodes[left].room < h->nodes[smallest].room))) {
        smallest = left;
    }

    if (right < h->size && (h->nodes[right].time < h->nodes[smallest].time ||
                            (h->nodes[right].time == h->nodes[smallest].time && h->nodes[right].room < h->nodes[smallest].room))) {
        smallest = right;
    }

    if (smallest != idx) {
        swap_nodes(&h->nodes[idx], &h->nodes[smallest]);
        heapify_down(h, smallest);
    }
}

void heapify_up(MinHeap* h, int idx) {
    if (idx == 0) return;
    int parent = (idx - 1) / 2;
    if (h->nodes[idx].time < h->nodes[parent].time ||
        (h->nodes[idx].time == h->nodes[parent].time && h->nodes[idx].room < h->nodes[parent].room)) {
        swap_nodes(&h->nodes[idx], &h->nodes[parent]);
        heapify_up(h, parent);
    }
}

void heap_push(MinHeap* h, long long time, int room) {
    if (h->size == h->capacity) {
        return;
    }
    h->nodes[h->size].time = time;
    h->nodes[h->size].room = room;
    h->size++;
    heapify_up(h, h->size - 1);
}

HeapNode heap_pop(MinHeap* h) {
    HeapNode root = h->nodes[0];
    h->nodes[0] = h->nodes[h->size - 1];
    h->size--;
    heapify_down(h, 0);
    return root;
}

int compare(const void* a, const void* b) {
    return (*(int**)a)[0] - (*(int**)b)[0];
}

int mostBooked(int n, int** meetings, int meetingsSize, int* meetingsColSize) {
    qsort(meetings, meetingsSize, sizeof(int*), compare);

    int* room_usage_count = (int*)calloc(n, sizeof(int));
    MinHeap* available_rooms = create_heap(n);
    MinHeap* busy_rooms = create_heap(n);

    for (int i = 0; i < n; i++) {
        heap_push(available_rooms, i, i);
    }

    for (int i = 0; i < meetingsSize; i++) {
        long long start = meetings[i][0];
        long long end = meetings[i][1];
        long long duration = end - start;

        while (busy_rooms->size > 0 && busy_rooms->nodes[0].time <= start) {
            HeapNode finished_room = heap_pop(busy_rooms);
            heap_push(available_rooms, finished_room.room, finished_room.room);
        }

        if (available_rooms->size > 0) {
            HeapNode room_node = heap_pop(available_rooms);
            int room_to_use = room_node.room;
            room_usage_count[room_to_use]++;
            heap_push(busy_rooms, end, room_to_use);
        } else {
            HeapNode room_node = heap_pop(busy_rooms);
            int room_to_use = room_node.room;
            long long new_end_time = room_node.time + duration;
            room_usage_count[room_to_use]++;
            heap_push(busy_rooms, new_end_time, room_to_use);
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

    free(room_usage_count);
    free(available_rooms->nodes);
    free(available_rooms);
    free(busy_rooms->nodes);
    free(busy_rooms);

    return result_room;
}
