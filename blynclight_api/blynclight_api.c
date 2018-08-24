// blynclight_api.c

#include "blynclight_api.h"
#include <time.h>

int ndevices = 0;
time_t last_update = 0;

int init_blynclights(void) 
{
  InitBlyncDevices(&ndevices, DEVINFO_ARRAY);
  last_update = time(NULL);
  return ndevices;
}

void fini_blynclights(void)
{
  ReleaseDevices(ndevices);
  last_update = 0;
}

int refresh_blynclights(void)
{
  fini_blynclights();
  init_blynclights();
  return ndevices;
}

unsigned int unique_device_id(byte index)
{
  unsigned int uid;
  UNIQUE_ID(index, uid);
  return uid;
}

byte device_type(byte index)
{
  if ((index > MAXIMUM_DEVICES) || (index<0))
    return INVALID_DEVICE_TYPE;
  return DEVINFO_ARRAY[index].byDeviceType;
}

int light_on(byte index, byte red, byte green, byte blue)
{
  return RETVAL(TurnOnRGBLights(index, red, green, blue));
}

int light_off(byte index)
{
  return RETVAL(TurnOffLight(index));
}

int bright(byte index, byte mode)
{
  switch(mode) {
    case 0:
      return RETVAL(SetLightDim(index));
      /* NOTREACHED */
    case 1:
      return RETVAL(ClearLightDim(index));
      /* NOTREACHED */
    default:
      break;
  }
  return -1;
}

int flash(byte index, byte mode)
{
  switch(mode) {
    case 0:
      return RETVAL(StopLightFlash(index));
      /* NOTREACHED */
    case 1:
      return RETVAL(StartLightFlash(index));
      /* NOTREACHED */
    default:
      break;
  }
  return 0;
}

int flash_speed(byte index, byte speed)
{
  return RETVAL(SelectLightFlashSpeed(index, speed));
}

int music(byte index, byte mode)
{
  switch(mode) {
    case 0:
      return RETVAL(StopMusicPlay(index));
    case 1:
      return RETVAL(StartMusicPlay(index));
    default:
      break;
  }
  return -1;
}

int music_repeat(byte index, byte mode)
{
  switch(mode) {
    case 0:
      return RETVAL(ClearMusicRepeat(index));
    case 1:
      return RETVAL(SetMusicRepeat(index));
    default:
      break;
  }
  return -1;
}

int music_volume(byte index, byte volume)
{
  return RETVAL(SetMusicVolume(index, volume));
}

int music_select(byte index, byte music)
{
  return RETVAL(SelectMusicToPlay(index, music));
}

int mute(byte index, byte mode)
{
  switch(mode) {
    case 0:
      return RETVAL(ClearVolumeMute(index));
    case 1:
      return RETVAL(SetVolumeMute(index));
    default:
      break;
  }
  return -1;
}


