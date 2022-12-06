<script setup lang="ts"></script>

<template>
  <header class="flex justify-center items-center gap-3 mt-2">
    <RouterLink :to="{ name: 'home' }">
      <h1 class="text-4xl">Bes Air App</h1>
    </RouterLink>
    <RouterLink :to="{ name: 'settings' }">
      <span class="text-3xl">⚙️</span>
    </RouterLink>
  </header>
</template>
