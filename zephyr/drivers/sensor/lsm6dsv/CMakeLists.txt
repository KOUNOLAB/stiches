if (CONFIG_LSM6DSV_SENSOR)
  zephyr_include_directories(.)
  
  zephyr_library()
  zephyr_library_sources(lsm6dsv.c)
endif()
