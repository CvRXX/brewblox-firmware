#!/usr/bin/env bash
# This file will be sourced by the shell in the container

# Generic
alias vg="rg --vimgrep -g '!external_libs'"

# Git
alias prettygit="git log --oneline --decorate --all --graph"
alias fetchap="git fetch --all -p"
alias rootd='cd "$(git rev-parse --show-toplevel)"'

function prunel() {
    # Removes all local branches that do not have a counterpart on 'origin' or 'upstream'
    # Careful: don't run this when current branch has no remote
    git branch -vv | grep 'origin/.*: gone]\|upstream/.*: gone]' | awk '{print $1}' | xargs -r git branch -d
}

function synchout() {
    fetchap \
    && git checkout "$1" \
    && git pull \
    && git submodule sync \
    && git submodule update --recursive \
    && prunel;
}

# ESP-IDF
alias dotdf=". /opt/esp/idf/export.sh"
alias get_idf=". /opt/esp/idf/export.sh"
