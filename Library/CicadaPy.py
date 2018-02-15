
import os
from ROOT import gSystem
import logging
import colorlog

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
base_format = '%(asctime)s{}[%(levelname)-8s] %(name)s(%(lineno)d) -> {}%(message)s'
formatter = colorlog.ColoredFormatter(
    base_format.format('%(log_color)s', '%(purple)s'),
    datefmt='%Y-%m-%dT%H:%M:%SZ'[:-1],
    reset=True,
)
handler = logging.StreamHandler()
handler.setFormatter(formatter)
logger.addHandler(handler)

def print_logo():

    print('\
        _                __     \n\
  _____(_)________ _____/ /___ _\n\
 / ___/ / ___/ __ `/ __  / __ `/\n\
/ /__/ / /__/ /_/ / /_/ / /_/ / \n\
\___/_/\___/\__,_/\__,_/\__,_/  \n')


def loadLibraries():
    print_logo()
    logger.debug("Import lib")
    path = os.path.join(os.path.dirname(
        os.path.abspath(__file__)), "lib")
    for afile in os.listdir(path):
        if afile.endswith(".dylib") or afile.endswith(".so"):
            logger.debug("\t->{}".format(os.path.join(path, afile)))
            gSystem.Load(os.path.join(path, afile))

    # logger.debug("Include headers")
    # gInterpreter.AddIncludePath("{}".format(os.path.join(os.path.dirname(os.path.abspath(__file__)), "include/Cicada/Scarab")))

    # path = os.path.join(os.path.dirname(os.path.abspath(__file__)), "include/Cicada")
    # for afile in os.listdir(path):
    #     if afile.endswith(".hh"):
    #         logger.debug("\t->{}".format(os.path.join(path, afile)))
    #         gInterpreter.ProcessLine('#include "{}"'.format(os.path.join(path, afile)))

    logger.info("All set!")

if __name__=="__main__":
    loadLibraries()
