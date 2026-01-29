#!/bin/bash
git log --max-count=5 | grep -e "commit " | tr --delete "commit "
