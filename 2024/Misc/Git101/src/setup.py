#!/usr/bin/env python3
import subprocess
import random
import os

def run_cmd(cmd):
	return subprocess.run(
		cmd.split(),
		capture_output = True,
		text = True
	).stdout


def file_to_hexdump(file_name: str) -> str:
	with open(file_name, "rb") as f:
		data = f.read()

	output = run_cmd(f"hexdump -vC {file_name}")
	output = output.split("\n")[:-1]
	random.shuffle(output)
	with open(f"{file}.hexdump", "w") as f:
		f.write("\n".join(output))

if __name__ == "__main__":

	def write_commit_line(idx):
		with open("../.commits-101", "w") as f:
			f.write(str(idx))

	file = "./main"
	git_dir = "./AOF-CTF-GIT101"
	commit_msg = "Trust me, a very descriptive message!"

	if not os.path.isfile(f"{file}.hexdump"):
		file_to_hexdump(file)
		print(f"Generated {file}.hexdump")
	else:
		print(f"{file}.hexdump already exists! Continuing")
	hexdump = open(f"{file}.hexdump", "r").read().splitlines()

	curr_dir = os.getcwd()
	if not os.path.isfile(".commits-101"):
		write_commit_line(0)
		lines = 0
	else:
		lines = int(open(".commits-101", "r").read())

	os.chdir(git_dir)

	print(f"Already wrote {lines} lines to git repo.")
	for i in range(lines, len(hexdump)):
		msg = hexdump[i]
		print(f"[*] Writing {msg}(Line {i}) to {file}")
		with open(file, "w") as f:
			f.write(msg)
		print("[*] Commiting to Repo")
		run_cmd(f"git add .")
		run_cmd(f"git commit -m test")
		write_commit_line(i)

	run_cmd(f"git push")

	os.chdir(curr_dir)