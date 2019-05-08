
.PHONY: clean all
all:goldcaptain

CPPFLAGS := -I/usr/local/include/SDL2 -D_THREAD_SAFE
CPPLIBS := -L/usr/local/lib -lSDL2 -lfreetype -lSDL2_mixer -lSDL2_image

temp/audioengine.o: audioengine.cpp stdafx.h /usr/local/include/SDL2/SDL.h \
  /usr/local/include/SDL2/SDL_main.h \
  /usr/local/include/SDL2/SDL_stdinc.h \
  /usr/local/include/SDL2/SDL_config.h \
  /usr/local/include/SDL2/SDL_platform.h \
  /usr/local/include/SDL2/begin_code.h \
  /usr/local/include/SDL2/close_code.h \
  /usr/local/include/SDL2/SDL_assert.h \
  /usr/local/include/SDL2/SDL_atomic.h \
  /usr/local/include/SDL2/SDL_audio.h \
  /usr/local/include/SDL2/SDL_error.h \
  /usr/local/include/SDL2/SDL_endian.h \
  /usr/local/include/SDL2/SDL_mutex.h \
  /usr/local/include/SDL2/SDL_thread.h \
  /usr/local/include/SDL2/SDL_rwops.h \
  /usr/local/include/SDL2/SDL_clipboard.h \
  /usr/local/include/SDL2/SDL_cpuinfo.h \
  /usr/local/include/SDL2/SDL_events.h \
  /usr/local/include/SDL2/SDL_video.h \
  /usr/local/include/SDL2/SDL_pixels.h \
  /usr/local/include/SDL2/SDL_rect.h \
  /usr/local/include/SDL2/SDL_surface.h \
  /usr/local/include/SDL2/SDL_blendmode.h \
  /usr/local/include/SDL2/SDL_keyboard.h \
  /usr/local/include/SDL2/SDL_keycode.h \
  /usr/local/include/SDL2/SDL_scancode.h \
  /usr/local/include/SDL2/SDL_mouse.h \
  /usr/local/include/SDL2/SDL_joystick.h \
  /usr/local/include/SDL2/SDL_gamecontroller.h \
  /usr/local/include/SDL2/SDL_quit.h \
  /usr/local/include/SDL2/SDL_gesture.h \
  /usr/local/include/SDL2/SDL_touch.h \
  /usr/local/include/SDL2/SDL_filesystem.h \
  /usr/local/include/SDL2/SDL_haptic.h \
  /usr/local/include/SDL2/SDL_hints.h \
  /usr/local/include/SDL2/SDL_loadso.h /usr/local/include/SDL2/SDL_log.h \
  /usr/local/include/SDL2/SDL_messagebox.h \
  /usr/local/include/SDL2/SDL_power.h \
  /usr/local/include/SDL2/SDL_render.h \
  /usr/local/include/SDL2/SDL_system.h \
  /usr/local/include/SDL2/SDL_timer.h \
  /usr/local/include/SDL2/SDL_version.h \
  /usr/local/include/SDL2/SDL_image.h util.h audioengine.h \
  /usr/local/include/SDL2/SDL_mixer.h
	g++ -c $< -o $@ -I/usr/local/include/SDL2 -D_THREAD_SAFE

temp/camera.o: camera.cpp stdafx.h /usr/local/include/SDL2/SDL.h \
  /usr/local/include/SDL2/SDL_main.h \
  /usr/local/include/SDL2/SDL_stdinc.h \
  /usr/local/include/SDL2/SDL_config.h \
  /usr/local/include/SDL2/SDL_platform.h \
  /usr/local/include/SDL2/begin_code.h \
  /usr/local/include/SDL2/close_code.h \
  /usr/local/include/SDL2/SDL_assert.h \
  /usr/local/include/SDL2/SDL_atomic.h \
  /usr/local/include/SDL2/SDL_audio.h \
  /usr/local/include/SDL2/SDL_error.h \
  /usr/local/include/SDL2/SDL_endian.h \
  /usr/local/include/SDL2/SDL_mutex.h \
  /usr/local/include/SDL2/SDL_thread.h \
  /usr/local/include/SDL2/SDL_rwops.h \
  /usr/local/include/SDL2/SDL_clipboard.h \
  /usr/local/include/SDL2/SDL_cpuinfo.h \
  /usr/local/include/SDL2/SDL_events.h \
  /usr/local/include/SDL2/SDL_video.h \
  /usr/local/include/SDL2/SDL_pixels.h \
  /usr/local/include/SDL2/SDL_rect.h \
  /usr/local/include/SDL2/SDL_surface.h \
  /usr/local/include/SDL2/SDL_blendmode.h \
  /usr/local/include/SDL2/SDL_keyboard.h \
  /usr/local/include/SDL2/SDL_keycode.h \
  /usr/local/include/SDL2/SDL_scancode.h \
  /usr/local/include/SDL2/SDL_mouse.h \
  /usr/local/include/SDL2/SDL_joystick.h \
  /usr/local/include/SDL2/SDL_gamecontroller.h \
  /usr/local/include/SDL2/SDL_quit.h \
  /usr/local/include/SDL2/SDL_gesture.h \
  /usr/local/include/SDL2/SDL_touch.h \
  /usr/local/include/SDL2/SDL_filesystem.h \
  /usr/local/include/SDL2/SDL_haptic.h \
  /usr/local/include/SDL2/SDL_hints.h \
  /usr/local/include/SDL2/SDL_loadso.h /usr/local/include/SDL2/SDL_log.h \
  /usr/local/include/SDL2/SDL_messagebox.h \
  /usr/local/include/SDL2/SDL_power.h \
  /usr/local/include/SDL2/SDL_render.h \
  /usr/local/include/SDL2/SDL_system.h \
  /usr/local/include/SDL2/SDL_timer.h \
  /usr/local/include/SDL2/SDL_version.h \
  /usr/local/include/SDL2/SDL_image.h util.h camera.h
	g++ -c $< -o $@ -I/usr/local/include/SDL2 -D_THREAD_SAFE

temp/dungeonmap.o: dungeonmap.cpp stdafx.h /usr/local/include/SDL2/SDL.h \
  /usr/local/include/SDL2/SDL_main.h \
  /usr/local/include/SDL2/SDL_stdinc.h \
  /usr/local/include/SDL2/SDL_config.h \
  /usr/local/include/SDL2/SDL_platform.h \
  /usr/local/include/SDL2/begin_code.h \
  /usr/local/include/SDL2/close_code.h \
  /usr/local/include/SDL2/SDL_assert.h \
  /usr/local/include/SDL2/SDL_atomic.h \
  /usr/local/include/SDL2/SDL_audio.h \
  /usr/local/include/SDL2/SDL_error.h \
  /usr/local/include/SDL2/SDL_endian.h \
  /usr/local/include/SDL2/SDL_mutex.h \
  /usr/local/include/SDL2/SDL_thread.h \
  /usr/local/include/SDL2/SDL_rwops.h \
  /usr/local/include/SDL2/SDL_clipboard.h \
  /usr/local/include/SDL2/SDL_cpuinfo.h \
  /usr/local/include/SDL2/SDL_events.h \
  /usr/local/include/SDL2/SDL_video.h \
  /usr/local/include/SDL2/SDL_pixels.h \
  /usr/local/include/SDL2/SDL_rect.h \
  /usr/local/include/SDL2/SDL_surface.h \
  /usr/local/include/SDL2/SDL_blendmode.h \
  /usr/local/include/SDL2/SDL_keyboard.h \
  /usr/local/include/SDL2/SDL_keycode.h \
  /usr/local/include/SDL2/SDL_scancode.h \
  /usr/local/include/SDL2/SDL_mouse.h \
  /usr/local/include/SDL2/SDL_joystick.h \
  /usr/local/include/SDL2/SDL_gamecontroller.h \
  /usr/local/include/SDL2/SDL_quit.h \
  /usr/local/include/SDL2/SDL_gesture.h \
  /usr/local/include/SDL2/SDL_touch.h \
  /usr/local/include/SDL2/SDL_filesystem.h \
  /usr/local/include/SDL2/SDL_haptic.h \
  /usr/local/include/SDL2/SDL_hints.h \
  /usr/local/include/SDL2/SDL_loadso.h /usr/local/include/SDL2/SDL_log.h \
  /usr/local/include/SDL2/SDL_messagebox.h \
  /usr/local/include/SDL2/SDL_power.h \
  /usr/local/include/SDL2/SDL_render.h \
  /usr/local/include/SDL2/SDL_system.h \
  /usr/local/include/SDL2/SDL_timer.h \
  /usr/local/include/SDL2/SDL_version.h \
  /usr/local/include/SDL2/SDL_image.h util.h dungeonmap.h
	g++ -c $< -o $@ -I/usr/local/include/SDL2 -D_THREAD_SAFE

temp/game.o: game.cpp stdafx.h /usr/local/include/SDL2/SDL.h \
  /usr/local/include/SDL2/SDL_main.h \
  /usr/local/include/SDL2/SDL_stdinc.h \
  /usr/local/include/SDL2/SDL_config.h \
  /usr/local/include/SDL2/SDL_platform.h \
  /usr/local/include/SDL2/begin_code.h \
  /usr/local/include/SDL2/close_code.h \
  /usr/local/include/SDL2/SDL_assert.h \
  /usr/local/include/SDL2/SDL_atomic.h \
  /usr/local/include/SDL2/SDL_audio.h \
  /usr/local/include/SDL2/SDL_error.h \
  /usr/local/include/SDL2/SDL_endian.h \
  /usr/local/include/SDL2/SDL_mutex.h \
  /usr/local/include/SDL2/SDL_thread.h \
  /usr/local/include/SDL2/SDL_rwops.h \
  /usr/local/include/SDL2/SDL_clipboard.h \
  /usr/local/include/SDL2/SDL_cpuinfo.h \
  /usr/local/include/SDL2/SDL_events.h \
  /usr/local/include/SDL2/SDL_video.h \
  /usr/local/include/SDL2/SDL_pixels.h \
  /usr/local/include/SDL2/SDL_rect.h \
  /usr/local/include/SDL2/SDL_surface.h \
  /usr/local/include/SDL2/SDL_blendmode.h \
  /usr/local/include/SDL2/SDL_keyboard.h \
  /usr/local/include/SDL2/SDL_keycode.h \
  /usr/local/include/SDL2/SDL_scancode.h \
  /usr/local/include/SDL2/SDL_mouse.h \
  /usr/local/include/SDL2/SDL_joystick.h \
  /usr/local/include/SDL2/SDL_gamecontroller.h \
  /usr/local/include/SDL2/SDL_quit.h \
  /usr/local/include/SDL2/SDL_gesture.h \
  /usr/local/include/SDL2/SDL_touch.h \
  /usr/local/include/SDL2/SDL_filesystem.h \
  /usr/local/include/SDL2/SDL_haptic.h \
  /usr/local/include/SDL2/SDL_hints.h \
  /usr/local/include/SDL2/SDL_loadso.h /usr/local/include/SDL2/SDL_log.h \
  /usr/local/include/SDL2/SDL_messagebox.h \
  /usr/local/include/SDL2/SDL_power.h \
  /usr/local/include/SDL2/SDL_render.h \
  /usr/local/include/SDL2/SDL_system.h \
  /usr/local/include/SDL2/SDL_timer.h \
  /usr/local/include/SDL2/SDL_version.h \
  /usr/local/include/SDL2/SDL_image.h util.h game.h timing.h \
  inputmanager.h dungeonmap.h imageutil.h camera.h
	g++ -c $< -o $@ -I/usr/local/include/SDL2 -D_THREAD_SAFE

temp/imageutil.o: imageutil.cpp stdafx.h /usr/local/include/SDL2/SDL.h \
  /usr/local/include/SDL2/SDL_main.h \
  /usr/local/include/SDL2/SDL_stdinc.h \
  /usr/local/include/SDL2/SDL_config.h \
  /usr/local/include/SDL2/SDL_platform.h \
  /usr/local/include/SDL2/begin_code.h \
  /usr/local/include/SDL2/close_code.h \
  /usr/local/include/SDL2/SDL_assert.h \
  /usr/local/include/SDL2/SDL_atomic.h \
  /usr/local/include/SDL2/SDL_audio.h \
  /usr/local/include/SDL2/SDL_error.h \
  /usr/local/include/SDL2/SDL_endian.h \
  /usr/local/include/SDL2/SDL_mutex.h \
  /usr/local/include/SDL2/SDL_thread.h \
  /usr/local/include/SDL2/SDL_rwops.h \
  /usr/local/include/SDL2/SDL_clipboard.h \
  /usr/local/include/SDL2/SDL_cpuinfo.h \
  /usr/local/include/SDL2/SDL_events.h \
  /usr/local/include/SDL2/SDL_video.h \
  /usr/local/include/SDL2/SDL_pixels.h \
  /usr/local/include/SDL2/SDL_rect.h \
  /usr/local/include/SDL2/SDL_surface.h \
  /usr/local/include/SDL2/SDL_blendmode.h \
  /usr/local/include/SDL2/SDL_keyboard.h \
  /usr/local/include/SDL2/SDL_keycode.h \
  /usr/local/include/SDL2/SDL_scancode.h \
  /usr/local/include/SDL2/SDL_mouse.h \
  /usr/local/include/SDL2/SDL_joystick.h \
  /usr/local/include/SDL2/SDL_gamecontroller.h \
  /usr/local/include/SDL2/SDL_quit.h \
  /usr/local/include/SDL2/SDL_gesture.h \
  /usr/local/include/SDL2/SDL_touch.h \
  /usr/local/include/SDL2/SDL_filesystem.h \
  /usr/local/include/SDL2/SDL_haptic.h \
  /usr/local/include/SDL2/SDL_hints.h \
  /usr/local/include/SDL2/SDL_loadso.h /usr/local/include/SDL2/SDL_log.h \
  /usr/local/include/SDL2/SDL_messagebox.h \
  /usr/local/include/SDL2/SDL_power.h \
  /usr/local/include/SDL2/SDL_render.h \
  /usr/local/include/SDL2/SDL_system.h \
  /usr/local/include/SDL2/SDL_timer.h \
  /usr/local/include/SDL2/SDL_version.h \
  /usr/local/include/SDL2/SDL_image.h util.h imageutil.h
	g++ -c $< -o $@ -I/usr/local/include/SDL2 -D_THREAD_SAFE

temp/inputmanager.o: inputmanager.cpp stdafx.h /usr/local/include/SDL2/SDL.h \
  /usr/local/include/SDL2/SDL_main.h \
  /usr/local/include/SDL2/SDL_stdinc.h \
  /usr/local/include/SDL2/SDL_config.h \
  /usr/local/include/SDL2/SDL_platform.h \
  /usr/local/include/SDL2/begin_code.h \
  /usr/local/include/SDL2/close_code.h \
  /usr/local/include/SDL2/SDL_assert.h \
  /usr/local/include/SDL2/SDL_atomic.h \
  /usr/local/include/SDL2/SDL_audio.h \
  /usr/local/include/SDL2/SDL_error.h \
  /usr/local/include/SDL2/SDL_endian.h \
  /usr/local/include/SDL2/SDL_mutex.h \
  /usr/local/include/SDL2/SDL_thread.h \
  /usr/local/include/SDL2/SDL_rwops.h \
  /usr/local/include/SDL2/SDL_clipboard.h \
  /usr/local/include/SDL2/SDL_cpuinfo.h \
  /usr/local/include/SDL2/SDL_events.h \
  /usr/local/include/SDL2/SDL_video.h \
  /usr/local/include/SDL2/SDL_pixels.h \
  /usr/local/include/SDL2/SDL_rect.h \
  /usr/local/include/SDL2/SDL_surface.h \
  /usr/local/include/SDL2/SDL_blendmode.h \
  /usr/local/include/SDL2/SDL_keyboard.h \
  /usr/local/include/SDL2/SDL_keycode.h \
  /usr/local/include/SDL2/SDL_scancode.h \
  /usr/local/include/SDL2/SDL_mouse.h \
  /usr/local/include/SDL2/SDL_joystick.h \
  /usr/local/include/SDL2/SDL_gamecontroller.h \
  /usr/local/include/SDL2/SDL_quit.h \
  /usr/local/include/SDL2/SDL_gesture.h \
  /usr/local/include/SDL2/SDL_touch.h \
  /usr/local/include/SDL2/SDL_filesystem.h \
  /usr/local/include/SDL2/SDL_haptic.h \
  /usr/local/include/SDL2/SDL_hints.h \
  /usr/local/include/SDL2/SDL_loadso.h /usr/local/include/SDL2/SDL_log.h \
  /usr/local/include/SDL2/SDL_messagebox.h \
  /usr/local/include/SDL2/SDL_power.h \
  /usr/local/include/SDL2/SDL_render.h \
  /usr/local/include/SDL2/SDL_system.h \
  /usr/local/include/SDL2/SDL_timer.h \
  /usr/local/include/SDL2/SDL_version.h \
  /usr/local/include/SDL2/SDL_image.h util.h inputmanager.h
	g++ -c $< -o $@ -I/usr/local/include/SDL2 -D_THREAD_SAFE

temp/main.o: main.cpp stdafx.h /usr/local/include/SDL2/SDL.h \
  /usr/local/include/SDL2/SDL_main.h \
  /usr/local/include/SDL2/SDL_stdinc.h \
  /usr/local/include/SDL2/SDL_config.h \
  /usr/local/include/SDL2/SDL_platform.h \
  /usr/local/include/SDL2/begin_code.h \
  /usr/local/include/SDL2/close_code.h \
  /usr/local/include/SDL2/SDL_assert.h \
  /usr/local/include/SDL2/SDL_atomic.h \
  /usr/local/include/SDL2/SDL_audio.h \
  /usr/local/include/SDL2/SDL_error.h \
  /usr/local/include/SDL2/SDL_endian.h \
  /usr/local/include/SDL2/SDL_mutex.h \
  /usr/local/include/SDL2/SDL_thread.h \
  /usr/local/include/SDL2/SDL_rwops.h \
  /usr/local/include/SDL2/SDL_clipboard.h \
  /usr/local/include/SDL2/SDL_cpuinfo.h \
  /usr/local/include/SDL2/SDL_events.h \
  /usr/local/include/SDL2/SDL_video.h \
  /usr/local/include/SDL2/SDL_pixels.h \
  /usr/local/include/SDL2/SDL_rect.h \
  /usr/local/include/SDL2/SDL_surface.h \
  /usr/local/include/SDL2/SDL_blendmode.h \
  /usr/local/include/SDL2/SDL_keyboard.h \
  /usr/local/include/SDL2/SDL_keycode.h \
  /usr/local/include/SDL2/SDL_scancode.h \
  /usr/local/include/SDL2/SDL_mouse.h \
  /usr/local/include/SDL2/SDL_joystick.h \
  /usr/local/include/SDL2/SDL_gamecontroller.h \
  /usr/local/include/SDL2/SDL_quit.h \
  /usr/local/include/SDL2/SDL_gesture.h \
  /usr/local/include/SDL2/SDL_touch.h \
  /usr/local/include/SDL2/SDL_filesystem.h \
  /usr/local/include/SDL2/SDL_haptic.h \
  /usr/local/include/SDL2/SDL_hints.h \
  /usr/local/include/SDL2/SDL_loadso.h /usr/local/include/SDL2/SDL_log.h \
  /usr/local/include/SDL2/SDL_messagebox.h \
  /usr/local/include/SDL2/SDL_power.h \
  /usr/local/include/SDL2/SDL_render.h \
  /usr/local/include/SDL2/SDL_system.h \
  /usr/local/include/SDL2/SDL_timer.h \
  /usr/local/include/SDL2/SDL_version.h \
  /usr/local/include/SDL2/SDL_image.h util.h game.h timing.h \
  inputmanager.h
	g++ -c $< -o $@ -I/usr/local/include/SDL2 -D_THREAD_SAFE

temp/timing.o: timing.cpp timing.h /usr/local/include/SDL2/SDL.h \
  /usr/local/include/SDL2/SDL_main.h \
  /usr/local/include/SDL2/SDL_stdinc.h \
  /usr/local/include/SDL2/SDL_config.h \
  /usr/local/include/SDL2/SDL_platform.h \
  /usr/local/include/SDL2/begin_code.h \
  /usr/local/include/SDL2/close_code.h \
  /usr/local/include/SDL2/SDL_assert.h \
  /usr/local/include/SDL2/SDL_atomic.h \
  /usr/local/include/SDL2/SDL_audio.h \
  /usr/local/include/SDL2/SDL_error.h \
  /usr/local/include/SDL2/SDL_endian.h \
  /usr/local/include/SDL2/SDL_mutex.h \
  /usr/local/include/SDL2/SDL_thread.h \
  /usr/local/include/SDL2/SDL_rwops.h \
  /usr/local/include/SDL2/SDL_clipboard.h \
  /usr/local/include/SDL2/SDL_cpuinfo.h \
  /usr/local/include/SDL2/SDL_events.h \
  /usr/local/include/SDL2/SDL_video.h \
  /usr/local/include/SDL2/SDL_pixels.h \
  /usr/local/include/SDL2/SDL_rect.h \
  /usr/local/include/SDL2/SDL_surface.h \
  /usr/local/include/SDL2/SDL_blendmode.h \
  /usr/local/include/SDL2/SDL_keyboard.h \
  /usr/local/include/SDL2/SDL_keycode.h \
  /usr/local/include/SDL2/SDL_scancode.h \
  /usr/local/include/SDL2/SDL_mouse.h \
  /usr/local/include/SDL2/SDL_joystick.h \
  /usr/local/include/SDL2/SDL_gamecontroller.h \
  /usr/local/include/SDL2/SDL_quit.h \
  /usr/local/include/SDL2/SDL_gesture.h \
  /usr/local/include/SDL2/SDL_touch.h \
  /usr/local/include/SDL2/SDL_filesystem.h \
  /usr/local/include/SDL2/SDL_haptic.h \
  /usr/local/include/SDL2/SDL_hints.h \
  /usr/local/include/SDL2/SDL_loadso.h /usr/local/include/SDL2/SDL_log.h \
  /usr/local/include/SDL2/SDL_messagebox.h \
  /usr/local/include/SDL2/SDL_power.h \
  /usr/local/include/SDL2/SDL_render.h \
  /usr/local/include/SDL2/SDL_system.h \
  /usr/local/include/SDL2/SDL_timer.h \
  /usr/local/include/SDL2/SDL_version.h
	g++ -c $< -o $@ -I/usr/local/include/SDL2 -D_THREAD_SAFE

temp/util.o: util.cpp stdafx.h /usr/local/include/SDL2/SDL.h \
  /usr/local/include/SDL2/SDL_main.h \
  /usr/local/include/SDL2/SDL_stdinc.h \
  /usr/local/include/SDL2/SDL_config.h \
  /usr/local/include/SDL2/SDL_platform.h \
  /usr/local/include/SDL2/begin_code.h \
  /usr/local/include/SDL2/close_code.h \
  /usr/local/include/SDL2/SDL_assert.h \
  /usr/local/include/SDL2/SDL_atomic.h \
  /usr/local/include/SDL2/SDL_audio.h \
  /usr/local/include/SDL2/SDL_error.h \
  /usr/local/include/SDL2/SDL_endian.h \
  /usr/local/include/SDL2/SDL_mutex.h \
  /usr/local/include/SDL2/SDL_thread.h \
  /usr/local/include/SDL2/SDL_rwops.h \
  /usr/local/include/SDL2/SDL_clipboard.h \
  /usr/local/include/SDL2/SDL_cpuinfo.h \
  /usr/local/include/SDL2/SDL_events.h \
  /usr/local/include/SDL2/SDL_video.h \
  /usr/local/include/SDL2/SDL_pixels.h \
  /usr/local/include/SDL2/SDL_rect.h \
  /usr/local/include/SDL2/SDL_surface.h \
  /usr/local/include/SDL2/SDL_blendmode.h \
  /usr/local/include/SDL2/SDL_keyboard.h \
  /usr/local/include/SDL2/SDL_keycode.h \
  /usr/local/include/SDL2/SDL_scancode.h \
  /usr/local/include/SDL2/SDL_mouse.h \
  /usr/local/include/SDL2/SDL_joystick.h \
  /usr/local/include/SDL2/SDL_gamecontroller.h \
  /usr/local/include/SDL2/SDL_quit.h \
  /usr/local/include/SDL2/SDL_gesture.h \
  /usr/local/include/SDL2/SDL_touch.h \
  /usr/local/include/SDL2/SDL_filesystem.h \
  /usr/local/include/SDL2/SDL_haptic.h \
  /usr/local/include/SDL2/SDL_hints.h \
  /usr/local/include/SDL2/SDL_loadso.h /usr/local/include/SDL2/SDL_log.h \
  /usr/local/include/SDL2/SDL_messagebox.h \
  /usr/local/include/SDL2/SDL_power.h \
  /usr/local/include/SDL2/SDL_render.h \
  /usr/local/include/SDL2/SDL_system.h \
  /usr/local/include/SDL2/SDL_timer.h \
  /usr/local/include/SDL2/SDL_version.h \
  /usr/local/include/SDL2/SDL_image.h util.h
	g++ -c $< -o $@ -I/usr/local/include/SDL2 -D_THREAD_SAFE


goldcaptain:temp/audioengine.o temp/camera.o temp/dungeonmap.o temp/game.o temp/imageutil.o temp/inputmanager.o temp/main.o temp/timing.o temp/util.o
	g++ -o $@ $< $(CPPLIBS)

clean:
	rm -f *.d; 	rm -f *.o; 	rm -f goldcaptain
