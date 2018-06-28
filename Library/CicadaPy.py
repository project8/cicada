
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



def loadLibraries(silence=False):
    import ROOT
    if hasattr(ROOT,"Cicada"):
        # logger.debug("Libraries already loaded...")
        return
    if silence:
        print_logo()        
        from ROOT import RooMsgService
        RooMsgService.instance().setSilentMode(True)
        RooMsgService.instance().setGlobalKillBelow(5)
        logger.setLevel(logging.INFO)
    else:
        # print_image()
        print_logo()

    from ROOT import gSystem, gInterpreter
    logger.debug("Import libraries...")
    path = os.path.join(os.path.dirname(
        os.path.abspath(__file__)), "lib")
    for afile in os.listdir(path):
        if afile.endswith(".dylib") or afile.endswith(".so"):
            logger.debug("\t->{}".format(os.path.join(path, afile)))
            gSystem.Load(os.path.join(path, afile))

    logger.info("All set!")
