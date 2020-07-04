#!/usr/bin/env bash

declare -a build_stages=( clean fmt execute )

function main() {
  local -r stages=${!1}

  function show() {
    local -r color_green='\033[0;32m'
    local -r color_reset='\033[0;0m' 
    printf "${color_green}[${1}]${color_reset}\n"
  }

  function run() {
    for stage in ${stages[@]}; do 
      show ${stage} && make ${stage}
    done
  }

  clear && run stages[@]
}

main build_stages[@]
