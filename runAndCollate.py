"""
script to run the string search and take time.
"""
from subprocess import run
from contextlib import contextmanager
import patternGenerator


@contextmanager
def cd(target):
    """
    chdir function generator
    :param target:
    :return:
    """
    old_dir = os.getcwd()
    os.chdir(os.path.expanduser(target))
    try:
        yield
    finally:
        os.chdir(old_dir)


# def gen_pattern(args):
#     run("python patternGenerator.py", args)


def run_search(args):
    with cd("cmake-build-release"):
        out = run("./201Assessment", args)
    return out


rk_time = dict()
bmh_time = dict()


for i in range(1, 2):
    cur_size = "{}M".format(i)
    rk_time[cur_size] = []
    bmh_time[cur_size] = []
    for j in range(1024):
        patternGenerator.main("1M")
        rk_time[cur_size].append(run_search("-rk"))
        bmh_time[cur_size].append(run_search("-bmh"))
