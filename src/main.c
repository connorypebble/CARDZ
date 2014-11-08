#include <pebble.h>

static Window *window;
static TextLayer *text_layer;

static void window_load(Window *window) {
	Layer *window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_bounds(window_layer);
	
	text_layer = text_layer_create((GRect) { .origin = { 0, 0 }, .size = { bounds.size.w, 20000 } });
	text_layer_set_text(text_layer, "In Flanders fields the poppies blow Between the crosses, row on row, That mark our place; and in the sky The larks, still bravely singing, fly Scarce heard amid the guns below. We are the Dead.");
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
	layer_add_child(window_layer, text_layer_get_layer(text_layer));
  
  void scroll_layer_scroll_down_click_handler	(	ClickRecognizerRef 	recognizer,
                                                void * 	context static Window *window; static TextLayer *text_layer;                        static void window_load(Window *window) { Layer *window_layer = window_get_root_layer(window);GRect bounds = layer_get_bounds(window_layer);text_layer = text_layer_create((GRect) { .origin = { 0, 0 }, .size = { bounds.size.w, 20000 } });
	
                                                                                                                                                                                    text_layer_set_text(text_layer, "Short days ago We lived, felt dawn, saw sunset glow, Loved and were loved, and now we lie In Flanders fields. Take up our quarrel with the foe, To you from failing hands we throw The torch; be yours to hold it high. If ye break faith with us who die We shall not sleep, though poppies grow In Flanders fields.");
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
	layer_add_child(window_layer, text_layer_get_layer(text_layer));
}

static void window_unload(Window *window) {
	text_layer_destroy(text_layer);
}

static void init(void) {
	window = window_create();
	window_set_window_handlers(window, (WindowHandlers) {
		.load = window_load,
		.unload = window_unload,
	});
	const bool animated = true;
	window_stack_push(window, animated);
}

static void deinit(void) {
	window_destroy(window);
}

int main(void) {
	init();
	
	APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);
	app_event_loop();
	deinit();
}