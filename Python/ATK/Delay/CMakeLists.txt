
FILE(GLOB_RECURSE
  PYTHON_MODULE_DELAY_SRC
  *.cpp
)

FILE(GLOB_RECURSE
  PYTHON_MODULE_DELAY_HEADERS
  *.h
)

SET(PYTHON_MODULE_DELAY_DEFINITIONS)
SET(PYTHON_MODULE_DELAY_INCLUDE)
SET(PYTHON_MODULE_DELAY_LIBRARIES ATKCore ATKDelay)

SET(PYTHON_MODULE_DELAY_NAME PythonDelay)
SET(PYTHON_MODULE_DELAY_FOLDER Delay)

ATK_add_python_module(PYTHON_MODULE_DELAY)
